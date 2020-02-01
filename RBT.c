#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int val,col;            // 0 == black  |||  1 == red
    struct _node *left,*right,*parent;
}RBT;

int   getHeight(RBT*);
void  inOrder(RBT*);
void  preOrder(RBT*);
void  postOrder(RBT*);
void  printLevel(RBT*,int);
void  printLevelwise(RBT*);
RBT  *makeNode(int);
RBT  *insert(RBT*,int);
RBT  *leftRotate(RBT*,RBT*);
RBT  *balanceTree(RBT*,RBT*);
RBT  *rightRotate(RBT *,RBT*);


int main()
{
    int n=0;
    RBT *root = NULL;

    printf("\nEnter elements to insert in Red Black Tree [ -99 TO STOP ] : \n");
    while(1)
    {
        scanf(" %d",&n);
        if(n== -99)
            break;
        root = insert(root,n);
        printLevelwise(root);
        printf("\n");
        inOrder(root);
        printf("\n\n");
    }




    return 0;
}

RBT *makeNode(int n)
{
    RBT *nd = (RBT*)malloc(sizeof(RBT));
    nd->val = n;
    nd->col = 1;        // default color is red
    nd->parent = nd->left = nd->right = NULL;

    return nd;
}

RBT *insert(RBT *root,int n)
{
    RBT *nd = makeNode(n);
    if(root)
    {
        RBT *prv = NULL, *ptr = root;
        while(ptr)
        {
            prv = ptr;
            if(ptr->val > n)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }
        if(prv->val > n)
            prv->left = nd;
        else
            prv->right = nd;
        nd->parent = prv;

        return root = balanceTree(root,nd);
    }
    nd->col = 0;        // root is black
    return nd;
}

RBT *balanceTree(RBT *root,RBT *nd)
{
    while(root&&nd &&(nd!=root) && (nd != root->left) && (nd != root->right) && (nd->parent->col==1))
    {
        RBT *uncle;
        if(nd->parent==nd->parent->parent->left)
            uncle = nd->parent->parent->right;
        if(nd->parent==nd->parent->parent->right)
            uncle = nd->parent->parent->left;
        if(uncle==NULL)
            nd = nd->parent->parent;
        else if(uncle->col==1)          //uncle is red
        {
            nd->parent->col = 0;        // change col of parent and uncle to B, grandparent to R
            uncle->col = 0;
            nd->parent->parent->col = 1;
            nd = nd->parent->parent;
        }
        else
        {
            if(nd->parent->parent->left==nd->parent && nd==nd->parent->left)        // Left left case
            {
                nd->parent->col = 0;
                nd->parent->parent->col = 1;
                root = rightRotate(root,nd->parent->parent);
            }
            else if(nd->parent->parent->left==nd->parent && nd==nd->parent->right)   // Left right case
            {
                nd->col = 0;
                nd->parent->parent->col = 1;
                root = leftRotate(root,nd->parent);
                root = rightRotate(root,nd->parent->parent);
            }
            else if(nd->parent->parent->right==nd->parent && nd==nd->parent->left)  // Right left case
            {
                nd->col = 0;
                nd->parent->parent->col = 1;
                root = rightRotate(root,nd->parent);
                root = leftRotate(root,nd->parent->parent);
            }
            else                                                                    // Right right case
            {
                nd->parent->col = 0;
                nd->parent->parent->col = 1;
                root = leftRotate(root,nd->parent->parent);
            }
        }
    }
    root->col = 0;      // root is black
    return root;
}

RBT *leftRotate(RBT *root,RBT *ptr)
{
    RBT *ptr_rght = ptr->right;
    ptr->right = ptr_rght->left;
    if(ptr->right)
        ptr->right->parent = ptr;

    ptr_rght->parent = ptr->parent;
    if(ptr->parent==NULL)
        root = ptr_rght;
    else if(ptr==ptr->parent->left)
        ptr->parent->left = ptr_rght;
    else
        ptr->parent->right = ptr_rght;

    ptr_rght->left = ptr;
    ptr->parent = ptr_rght;

    return root;
}

RBT *rightRotate(RBT *root,RBT *ptr)
{
    RBT *ptr_lft = ptr->left;
    ptr->left = ptr_lft->right;
    if(ptr->left)
        ptr->left->parent = ptr;

    ptr_lft->parent = ptr->parent;
    if(ptr->parent==NULL)
        root = ptr_lft;
    else if(ptr==ptr->parent->left)
        ptr->parent->left = ptr_lft;

    ptr_lft->right = ptr;
    ptr->parent = ptr_lft;

    return root;
}

void preOrder(RBT *root)
{
    if(root)
    {
        printf("\nvalue = %d , color = %d",root->val,root->col);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(RBT *root)
{
    if(root)
    {
        inOrder(root->left);
        printf("\nvalue = %d , color = %d",root->val,root->col);
        inOrder(root->right);
    }
}

void postOrder(RBT *root)
{
    if(root)
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("\nvalue = %d , color = %d",root->val,root->col);
    }
}

int getHeight(RBT *root)
{
    if(root)
    {
        int lh = getHeight(root->left);
        int rh = getHeight(root->right);
        return (lh>rh?lh:rh)+1;
    }
    return 0;
}

void printLevel(RBT *root,int n)
{
    if(root)
    {
        if(n==1)
            printf(" %d [%d]  ",root->val,root->col);
        else
        {
            printLevel(root->left,n-1);
            printLevel(root->right,n-1);
        }
    }
}

void printLevelwise(RBT *root)
{
    int i,h=getHeight(root);
    for(i=1;i<=h;i++)
    {
        printLevel(root,i);
        printf("\n");
    }
}
