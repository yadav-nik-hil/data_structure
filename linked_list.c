#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct _node
{
    int val;
    struct _node* next;
}Node;

Node *makeNode(int);
void  print(Node*);
void  printRev(Node*);
float average(Node*);
Node *insAfter_info(Node*,Node*,int,int);
Node *insAfter_pos(Node*,Node*,int,int);
Node *insBefore_info(Node*,Node*,int,int);
void  reverse(Node*);
Node *new_sortList(Node*,int);
Node *delNode_info(Node*,int);
Node *delNode_pos(Node*,int);
Node *swap_pos(Node*,Node**,int,int);
Node *append(Node*,Node**,int);

int main()
{
    int n,a,b;
    float avg;
    Node *start=NULL, *last= NULL, *nd=NULL;
    printf("\nEnter the numbers for list [Enter -999 to stop]: \n");
    while(1)
    {
        scanf("%d",&n);
        if(n==-999)
            break;
        start = append(start,&last,n);
    }
    print(start);

    /*Reversing of the list
    reverse(start);
    nd = start;
    start = last;
    last = nd;
    print(start);
    */

    printf("\nEnter the positions to swap : ");
    scanf("%d%d",&a,&b);
    start = swap_pos(start,&last,a,b);
    print(start);

    printf("\nEnter the positions to swap : ");
    scanf("%d%d",&a,&b);
    start = swap_pos(start,&last,a,b);
    print(start);

    printf("\nEnter the positions to swap : ");
    scanf("%d%d",&a,&b);
    start = swap_pos(start,&last,a,b);
    print(start);

    printf("\nEnter the positions to swap : ");
    scanf("%d%d",&a,&b);
    start = swap_pos(start,&last,a,b);
    print(start);

    printf("\nEnter the positions to swap : ");
    scanf("%d%d",&a,&b);
    start = swap_pos(start,&last,a,b);
    print(start);

    printf("\nEnter the positions to swap : ");
    scanf("%d%d",&a,&b);
    start = swap_pos(start,&last,a,b);
    print(start);

    return 0;
}

Node* makeNode(int n)
{
    Node* nd =  (Node*)malloc(sizeof(Node));
    nd->val = n;
    nd->next = NULL;

    return nd;
}

Node *append(Node *start,Node **p2last,int n)
{
    if(start==NULL)
        *p2last = start = makeNode(n);
    else
        *p2last = (*p2last)->next = makeNode(n);

    return start;
}

void print(Node* ptr)
{
    printf("[ ");
    while(ptr)
    {
        printf("%d  ",ptr->val);
        ptr = ptr->next;
    }
    printf("\b]\n");
}

void printRev(Node* start)
{
    if(start==NULL)
        return;
    printRev(start->next);
    printf("%d\n",start->val);
}

float average(Node* ptr)
{
    int sum=0,n=0;
    while(ptr)
    {
        sum+=ptr->val;
        n++;
        ptr = ptr->next;
    }
    printf("\nAverage = %f",(float)sum/n);
    printf("\nSum = %d",sum);
    printf("\nNumber of nodes = %d",n);

    return (float)sum/n;
}

Node* insAfter_pos(Node* start,Node* last,int n,int pos)
{
    Node* nd = makeNode(n);
    while(start && pos>1)
    {
        start = start->next;
        if(pos==0)
        {
            nd->next = start->next;
            start->next = nd;
            if(start==last)
                last = nd;
        }

    return last;
    }
}

Node* insAfter_info(Node* start,Node* last,int n,int info)
{
    Node* nd=makeNode(n);
    while(start && start->val!=info)
    {
        start = start->next;
    }
    if(start && start->val==info)
    {
        nd->next=start->next;
        start->next = nd;
        if(start==last)
            last=nd;
    }
    if(start==NULL)
        printf("\nThe given information is not available\n");

    return last;
}

Node* insBefore_pos(Node* start,Node* last,int n, int pos)
{
    Node* nd = makeNode(n);
    if(pos==1)
    {
        nd->next = start;
        start = nd;
    }
    else
        last = insAfter_pos(start,last,n,pos-1);

    return start;
}

Node* insBefore_info(Node* start,Node* last,int n,int info)
{
    Node* nd = makeNode(n);
    if(start && start->val==info)
    {
        nd->next = start;
        start = nd;
    }
    else
    {
        Node* prev=start;
        start = start->next;
        while(start && start->val!=info)
        {
            prev = start;
            start = start->next;
        }
        if(start && start->val==info)
        {
            nd->next = start;
            prev->next = nd;
        }
    }
    if(start==NULL)
        printf("\nThe given information is not available\n");

    return start;
}

void reverse(Node* ptr)
{
    if(ptr==NULL || ptr->next==NULL)
        return;
    reverse(ptr->next);
    ptr->next->next = ptr;
    ptr->next = NULL;
}

Node *reverse(Node *ptr)
{
	Node *nd;
	if(ptr==NULL || ptr->next==NULL)
        	return ptr;
	nd = reverse(ptr->next);
    	ptr->next->next = ptr;
    	ptr->next = NULL;

	return nd;
}

Node* new_sortList(Node* start, int n)
{
    Node *ptr, *prv;
    for(ptr=start;ptr && n>ptr->val;prv=ptr,ptr=ptr->next);

    Node *nd = makeNode(n);
    nd->next = ptr;
    if(ptr==start)
        start = nd;
    else
        prv->next = nd;

    return start;
}

Node *delNode_pos(Node *start,int pos)
{
    int i=1;
    Node *ptr=start;
    if(pos==1)
        start = start->next;
    else
    {
        while(ptr && i<pos)
        {
            if(i==pos-1)
                ptr->next = ptr->next->next;
            else
            {
                ptr = ptr->next;
                i++;
            }
        }
    }
    return start;
}

Node *delNode_info(Node *start,int info)
{
    Node *prv = start,*ptr = start->next;
    if(ptr==NULL)
    {
        if(prv->val==info)
            return NULL;
    }
    while(ptr)
    {
        if(prv==start && prv->val==info)
        {
            start = prv = ptr;
            ptr = ptr->next;
        }
        if(ptr->val==info)
           ptr = prv->next = ptr->next;
        else
        {
            ptr = ptr->next;
            prv = prv->next;
        }
    }

    return start;
}

Node *swap_pos(Node *start,Node **p2last,int a,int b)
{
    int c;
    if(a==b || start==NULL || start->next==NULL)
        return start;
    if(a>b)
        ((c=a)?(a=b)&&(b=c):(a=b)&&(b=c));
    Node *ptr,*prv,*ptr1=NULL,*ptr2=NULL,*prv1,*prv2;
    for(prv=NULL,ptr=start;ptr && a>1;prv=ptr,ptr=ptr->next,a--,b--);
    if(ptr)
    {
        prv1 = prv;
        ptr1 = ptr;
        for(;ptr && b>1;b--,prv=ptr,ptr=ptr->next);
        if(ptr)
        {
            prv2 = prv;
            ptr2 = ptr;
        }
        else
        {
            printf("\nPositions entered exceeded their limits.");
            return start;
        }
    }
    else
    {
        printf("\nPositions entered exceeded their limits.");
        return start;
    }

    ptr = ptr1->next;
    ptr1->next = ptr2->next;
    ptr2->next = ptr;
    if(!prv1)
    {
        start = ptr2;
        prv2->next = ptr1;
    }
    else
    {
        prv1->next = ptr2;
        prv2->next = ptr1;
    }
    if(*p2last==ptr2)
        *p2last = ptr1;

    return start;
}
