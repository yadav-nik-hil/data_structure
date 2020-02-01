#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct _node
{
    int val;
    struct _node *next;
}Node;

Node *makeNode(n)
{
    Node *nd = (Node*)malloc(sizeof(Node));
    nd->val = n;
    nd->next = NULL;

    return nd;
}

void print(Node*);

Node *append(Node*,int);
Node *rmvNode(Node*,int);
Node *alt_del(Node*);
Node *insAfter(Node*,int,int);
Node *insBefore(Node*,int,int);
Node *locate(Node*,int);

int main()
{
    int n,info;
    Node *last=NULL,*nd;
    printf("\nEnter the values for the list [Enter -999 to stop]: ");
    while(1)
    {
        scanf("%d",&n);
        if(n==-999)
            break;
        last = append(last,n);
    }
    print(last);

    printf("\nEnter the number to be removed form the List : ");
    scanf("%d",&info);
    last = rmvNode(last,info);
    print(last);

    printf("\nEnter the information of Node after which insertion happens : ");
    scanf("%d",&info);
    printf("\nNow, Enter value to insert : ");
    scanf("%d",&n);
    last = insAfter(last,info,n);
    print(last);

    printf("\nEnter the information of Node before which insertion happens : ");
    scanf("%d",&info);
    printf("\nNow, Enter the value to insert : ");
    scanf("%d",&n);
    last = insBefore(last,info,n);
    print(last);

    printf("\nEnter the value you want to find : ");
    scanf("%d",&info);
    nd = locate(last,info);
    if(nd!=NULL)
        printf("\nValue has been found.");
    else
        printf("\nValue is not in the List.");

    return 0;
}

void print(Node* last)
{
    printf("\n");
    if(last)
    {
        Node *ptr=last;
        printf("[ ");
        do
        {
            ptr = ptr->next;
            printf("%d  ",ptr->val);
        }while(ptr!=last);
        printf("\b]\n");
    }
    else
        printf("Empty List");
}

Node *append(Node *last,int n)
{
    Node *nd = makeNode(n);
    if(last==NULL)
        last = nd;
    else
        nd->next = last->next;
    last->next = nd;

    return nd;
}

//Function to locate an item in the circular list
Node *locate(Node *last,int info)
{
    if(last==NULL)
        return NULL;
    Node *ptr;
    int i=0;
    for(ptr=last->next;ptr!=last && ptr->val!=info;ptr=ptr->next,i++);
    if(ptr->val==info)
    {
        printf("\nThe Value %d has been found %d place(s) from the start.",info,i);
        return ptr;
    }
    return NULL;
}

//Info based bcz pos based can't be defined
/*
Node *rmvNode(Node *last,int info)
{
    if(last->val==info && last->next==last)
        return NULL;
    Node *prv=last,*ptr=last->next;
    do
    {
        if(ptr->val==info)
            ptr = prv->next = ptr->next;
        else
        {
            prv = prv->next;
            ptr = ptr->next;
        }
    }while(ptr!=last);

    //This below code checks for the last pointer as the do-while fails to check *last
    if(ptr->val==info)
    {
        if(ptr->next==last)
            return NULL;
        ptr = last = prv->next = ptr->next;                //BTW  ptr==last
    }

    return last;
}*/

Node *rmvNode(Node *last,int info)
{
    Node *prv,*ptr;
    if(last==NULL)
        return NULL;
    for(prv=last,ptr=last->next;ptr!=last && ptr->val!=info;prv=ptr,ptr=ptr->next);
    if(ptr->val==info)
    {
        if(prv==ptr)
            last==NULL;
        else
        {
            prv->next = ptr->next;
            if(ptr==last)
                last = prv;
        }
        free(ptr);
    }
    return last;
}

//The insBefore function with one pointer
Node *insBefore(Node *last,int info,int n)
{
    if(last==NULL)
        return NULL;
    Node *ptr=last->next;
    Node *nd = makeNode(n);
    while(ptr->next->val!=info)
        ptr = ptr->next;
    nd->next = ptr->next;
    ptr->next = nd;

    return last;                                 //BTW *last will never change in insBefore()
}

//The insBefore function with two pointers
/*Node *insBefore(Node *last,int info,int n)
{
    Node *prv=last,*ptr=last->next;
    Node *nd = makeNode(n);
    while(ptr->val!=info)
    {
        if(ptr==last)
        {
            printf("\nThe information is not available in the List.");
            return last;
        }
        prv = prv->next;
        ptr = ptr->next;
    }
    nd->next = ptr;
    prv->next = nd;

    return last;
}*/

Node *insAfter(Node *last,int info,int n)
{
    if(last==NULL)
        return NULL;
    Node *ptr=last->next;
    Node *nd = makeNode(n);
    while(ptr->val!=info)
    {
        if(ptr==last)
        {
            printf("\nThe information is not present in the List.\n");
            return last;
        }
        ptr = ptr->next;
    }
    nd->next = ptr->next;
    ptr->next = nd;
    if(ptr==last)
        last = nd;

    return last;
}

/*Node *alt_del(Node *last)
{
    if(last==NULL)
        return NULL;
    Node *start;
    char c;
    printf("\nDelete Odd or Even placed Nodes ['O' for Odd and 'E' for even] : ");
    scanf("%c",&c);
    if(c=='o' || c=='O')
        start=last->next;
    if(c=='e' || c=='E')
        start=last->next->next;



    return last;
}*/
