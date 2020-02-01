#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _itree
{
    int low,high,max;
    struct _itree *right,*left;
}interTree;


int        getHeight(interTree*);
void       swap(int*,int*);
void       inOrder(interTree*);
void       preOrder(interTree*);
void       postOrder(interTree*);
void       printLevel(interTree*,int);
void       printLevelwise(interTree*);
interTree *makeNode(int,int);
interTree *insert(interTree*,int,int);
interTree *search(interTree*,int,int);


int main()
{
    interTree *root = NULL,*ptr=NULL;
    int n=0,m=0,i;

    printf("\nInsert intervals for the Tree [ -99 TO STOP ] : \n");
    while(n!=-99)
    {
        scanf(" %d%d",&n,&m);
        if(n!=-99 && m!=-99)
        {
            if(n==m)
            {
                printf("\nERROR!!   Enter a valid Interval...\n");
                continue;
            }
            root = insert(root,n,m);
        }
        else
            break;
    }

    i = getHeight(root);
    printf("\nHeight = %d\n",i);

    printLevelwise(root);

    n=m=0;
    while(1)
    {
        printf("\nEnter the interval to search [ -99 TO STOP ] : \t");
        scanf(" %d%d",&n,&m);
        if(n== -99 || m== -99)
            break;
        ptr = search(root,n,m);
        if(ptr)
            printf("\nIntersecting Interval Found... [ %d , %d ]\n",ptr->low,ptr->high);
        else
            printf("\nNo intersecting Interval...\n");
    }


    printf("\n....EXITING....\n");
    return 0;
}

interTree *makeNode(int lo,int hi)
{
    interTree *nd = (interTree*)malloc(sizeof(interTree));
    if(lo>hi)
        swap(&lo,&hi);
    nd->low = lo;
    nd->max = nd->high = hi;
    nd->right = nd->left = NULL;

    return nd;
}

interTree *insert(interTree *root,int lo,int hi)
{
    interTree *nd = makeNode(lo,hi);
    if(root)
    {
        interTree *ptr=root,*prv=NULL;
        while(ptr)
        {
            prv = ptr;
            if(ptr->max < hi)
                ptr->max = hi;
            if(ptr->low > lo)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(prv->low > lo)
            prv->left = nd;
        else
            prv->right = nd;

        return root;
    }
    return nd;
}

void swap(int *p,int *q)
{
    int tmp = *p;
    *p = *q;
    *q = tmp;
}

interTree *search(interTree *root,int lo,int hi)
{
    if(root)
    {
        interTree *ptr=root;
        if(lo>hi)
            swap(&lo,&hi);
        while(ptr && (lo > ptr->high || ptr->low > hi))
        {
            if(ptr->left && lo <= ptr->left->max)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        return ptr;
    }
    return NULL;
}

void inOrder(interTree *root)
{
    inOrder(root->left);
    printf("  [ %d , %d]  ",root->low,root->high);
    inOrder(root->right);
}

void preOrder(interTree *root)
{
    printf("  [ %d , %d]  ",root->low,root->high);
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(interTree *root)
{
    inOrder(root->left);
    inOrder(root->right);
    printf("  [ %d , %d]  ",root->low,root->high);
}

void printLevel(interTree *root,int n)
{
    if(root)
    {
        if(n==1)
            printf("  [ %d , %d ]  ",root->low,root->high);
        else
        {
            printLevel(root->left,n-1);
            printLevel(root->right,n-1);
        }
    }
}

void printLevelwise(interTree *root)
{
    int i,h=getHeight(root);
    for(i=1;i<=h;i++)
    {
        printLevel(root,i);
        printf("\n");
    }
}

int getHeight(interTree *root)
{
    if(root)
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return (lh>rh?lh:rh)+1;
    }
    return 0;
}
