#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _node
{
    int val,size;
    struct _node *left,*right;
}BST;


int   getHeight(BST*);
int   getRank(BST*,int);
BST  *newCopy(BST*);
BST  *makeNode(int);
BST  *del(BST*,int);
BST  *newMirror(BST*);
BST  *insert(BST*,int);
BST  *select(BST*,int);
BST  *del_rank(BST*,int);
void  mirror(BST*);
void  inOrder(BST*);
void  preOrder(BST*);
void  postOrder(BST*);
void  printLevel(BST*,int);
void  printLevelwise(BST*);


int main()
{
    BST *root = NULL,*new_root=NULL,*ptr;
    int n=0,i;
    printf("\nInsert elements for the Tree [ -99 TO STOP ] : \n");
    while(n!=-99)
    {
        scanf(" %d",&n);
        if(n==-99)
            break;
        root = insert(root,n);
    }

    i = getHeight(root);
    printf("\nHeight = %d\n",i);
    printLevelwise(root);
    /*
    n=0;
    do{
        printf("\nEnter the number to delete [ -99 TO STOP ] : \t");
        scanf(" %d",&n);
        root = del(root,n);
        printLevelwise(root);
    }while(n!= -99);
    */
    /*
    n=0;
    do{
        printf("\nEnter the rank you want to search [ -99 TO STOP ]: \t");
        scanf(" %d",&n);
        if(n>0)
            ptr = select(root,n);
        if(ptr)
            printf("\n%d rank element = %d\n",n,ptr->val);
        else
            printf("\nCan't be found...\n");
    }while(n!= -99);
    */
    /*
    n=0;
    do{
        printf("\nEnter the number whose rank is to be found : \t");
        scanf(" %d",&n);
        i = getRank(root,n);
        if(i)
            printf("\nRank of %d is = %d\n",n,i);
        else
            printf("\nElement not found...\n");
    }while(n!= -99);
    */
    /*
    printf("\nCreating a copy of Tree\n");
    new_root = newCopy(root);
    printLevelwise(new_root);

    printf("\nMirroring the Tree\n");
    mirror(new_root);
    printLevelwise(new_root);
    */


    printf("\n....EXITING....\n");
    return 0;
}

BST *makeNode(int n)
{
    BST *nd = (BST*)malloc(sizeof(BST));
    nd->val = n;
    nd->left = nd->right = NULL;
    nd->size = 1;

    return nd;
}

BST *insert(BST *root,int n)
{
    BST *nd = makeNode(n);
    if(root)
    {
        BST *ptr=root,*prv=NULL;
        while(ptr)
        {
            prv = ptr;
            (ptr->size)++;
            if(ptr->val > n)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(prv->val > n)
            prv->left = nd;
        else
            prv->right = nd;

        return root;
    }
    return nd;
}

BST *del(BST *root,int n)
{
    if(root)
    {
        BST *prv=NULL,*ptr=root,*sz;
        while(ptr && n!=ptr->val)
        {
            prv = ptr;
            if(ptr->val > n)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(ptr)
        {
            if(ptr->left==NULL && ptr->right==NULL)     // no child
            {
                if(ptr==root)
                    return NULL;
                if(ptr==prv->left)
                    prv->left = NULL;
                else
                    prv->right = NULL;
            }
            else if((ptr->left && !ptr->right) || (!ptr->left && ptr->right))       // 1 child
            {
                if(ptr==root)
                    return (ptr->left)?ptr->left:ptr->right;
                if(ptr==prv->left)
                    prv->left = (ptr->left)?ptr->left:ptr->right;
                else
                    prv->right = (ptr->left)?ptr->left:ptr->right;
            }
            else                    // 2 children
            {
                BST *nd=ptr;
                ptr = ptr->left;
                while(ptr->right)
                {
                    prv = ptr;
                    ptr = ptr->right;
                }
                nd->val = ptr->val;
                if(ptr==nd->left)
                {
                    prv = nd;
                    nd->left = ptr->left;
                }
                else
                    prv->right = ptr->left;
            }
            sz = root;
            while(sz->val!=prv->val)
            {
                (sz->size)--;
                if(sz->val > prv->val)
                    sz = sz->left;
                else
                    sz = sz->right;
            }
            (prv->size)--;
        }
    }
    return root;
}

BST *del_rank(BST *root,int rank)
{
    BST *ptr = select(root,rank);
    return del(root,ptr->val);
}

int getRank(BST *root,int n)
{
    if(root)
    {
        int k = (root->left) ? (root->left->size +1) : 1;
        if(n==root->val)
            return k;
        else
        {
            while(root && n!=root->val)
            {
                if(root->val > n)
                {
                    root = root->left;
                    if(root->right)
                        k -= root->right->size;
                    k--;
                }
                else
                {
                    root = root->right;
                    if(root->left)
                        k += root->left->size;
                    k++;
                }
            }
            if(root)
                return k;
            else
                return 0;
        }
    }
    return 0;
}

BST *select(BST *root,int n)
{
    int k;
    if(root)
    {
        if(root->left)
            k = root->left->size + 1;
        else
            k = 1;
        if(n==k)
            return root;
        else if(k>n)
            return select(root->left,n);
        else
            return select(root->right,n-k);
    }
    return NULL;
}

int getHeight(BST *root)
{
    if(root)
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return (lh>rh?lh:rh)+1;
    }
    return 0;
}

void inOrder(BST *root)
{
    inOrder(root->left);
    printf(" %d ",root->val);
    inOrder(root->right);
}

void preOrder(BST *root)
{
    printf(" %d ",root->val);
    inOrder(root->left);
    inOrder(root->right);
}

void postOrder(BST *root)
{
    inOrder(root->left);
    inOrder(root->right);
    printf(" %d ",root->val);
}

void printLevel(BST *root,int n)
{
    if(root)
    {
        if(n==1)
            printf(" %d ",root->val);
        else
        {
            printLevel(root->left,n-1);
            printLevel(root->right,n-1);
        }
    }
}

void printLevelwise(BST *root)
{
    int i,h=getHeight(root);
    for(i=1;i<=h;i++)
    {
        printLevel(root,i);
        printf("\n");
    }
}

void mirror(BST *root)
{
    if(root)
    {
        BST *tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        mirror(root->left);
        mirror(root->right);
    }
}

BST *newMirror(BST *root)
{
    BST *new_root = NULL;
    new_root = newCopy(root);
    mirror(new_root);

    return new_root;
}

BST *newCopy(BST *root)
{
    if(root)
    {
        BST *nd = makeNode(root->val);
        nd->left = newCopy(root->left);
        nd->right = newCopy(root->right);
        return nd;
    }
    return NULL;
}
