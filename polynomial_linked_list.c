#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct _node
{
    int coeff;
    int deg;
    struct _node *next;
}Node;

typedef struct
{
    int degree;
    Node *start;
}Polynomial;

Node *makeNode(int,int);
Polynomial getPoly(int);
void printPoly(Polynomial);
Polynomial addPoly(Polynomial,Polynomial);
Polynomial subPoly(Polynomial,Polynomial);
Polynomial multPoly(Polynomial,Polynomial);
float evalPoly(Polynomial,float);

int main()
{
    int d;
    float eval,x;
    Polynomial p,q,sum,sub1,sub2,mult;

    printf("Enter the degree of Polynomial 1 : ");
    scanf("%d",&d);
    p = getPoly(d);

    printf("\nEnter the degree of Polynomial 2 : ");
    scanf("%d",&d);
    q = getPoly(d);

    printf("\nPolynomial 1 : ");
    printPoly(p);
    printf("\n");

    printf("\nPolynomial 2 : ");
    printPoly(q);
    printf("\n");

    sum = addPoly(p,q);
    printf("\nThe sum of Polynomial 1 and Polynomial 2 is : ");
    printPoly(sum);
    printf("\n");

    sub1 = subPoly(p,q);
    printf("\nPolynomial 1 - Polynomial 2 : ");
    printPoly(sub1);
    printf("\n");

    sub2 = subPoly(q,p);
    printf("\nPolynomial 2 - Polynomial 1 : ");
    printPoly(sub2);
    printf("\n");

    mult = multPoly(p,q);
    printf("\nThe multiplication of Polynomial 1 and Polynomial 2 is : ");
    printPoly(mult);
    printf("\n");

    printf("\nEnter the value at which Polynomial 1 has to be evaluated : ");
    scanf("%f",&x);
    eval = evalPoly(p,x);
    printf("\n");

    printf("\nEnter the value at which Polynomial 2 has to be evaluated : ");
    scanf("%f",&x);
    eval = evalPoly(q,x);
    printf("\n");

    printf("\nEnter the value at which Polynomial sum has to be evaluated : ");
    scanf("%f",&x);
    eval = evalPoly(sum,x);
    printf("\n");

    printf("\nEnter the value at which Polynomial sub1 has to be evaluated : ");
    scanf("%f",&x);
    eval = evalPoly(sub1,x);
    printf("\n");

    printf("\nEnter the value at which Polynomial sub2 has to be evaluated : ");
    scanf("%f",&x);
    eval = evalPoly(sub2,x);
    printf("\n");

    printf("\nEnter the value at which Polynomial mult has to be evaluated : ");
    scanf("%f",&x);
    eval = evalPoly(mult,x);
    printf("\n");

    return 0;
}

void printPoly(Polynomial p)
{
    int first = 1;
    if(p.start==NULL)
        printf("0\n");
    while(p.start)
    {
        if((p.start->deg)>1)
        {
            if(first)
            {
                if(p.start->coeff==1)
                    printf("x^%d",p.start->deg);
                else if(p.start->coeff==-1)
                    printf("-x^%d",p.start->deg);
                else
                    printf("%dx^%d",p.start->coeff,p.start->deg);
            }
            else
            {
                if(p.start->coeff==1)
                    printf(" + x^%d",p.start->deg);
                else if(p.start->coeff==-1)
                    printf(" - x^%d",p.start->deg);
                else
                    printf(" %+dx^%d",p.start->coeff,p.start->deg);
            }
        }
        else if((p.start->deg)==1)                   //BTW p.start->deg==1
        {
            if(first)
            {
                if(p.start->coeff==1)
                    printf("x");
                else if(p.start->coeff==-1)
                    printf("-x");
                else
                    printf("%dx",p.start->coeff);
            }
            else
            {
                if(p.start->coeff==1)
                    printf(" + x");
                else if(p.start->coeff==-1)
                    printf(" - x");
                else
                    printf(" %+dx",p.start->coeff);
            }

        }
        else                                         //BTW p.start->deg==0
        {
            if(first)
                printf("%d",p.start->coeff);
            else
                printf(" %+d",p.start->coeff);
        }
        first = 0;
        p.start = p.start->next;
    }
}

Node *makeNode(int c, int d)
{
    Node *nd;
    nd = (Node*)malloc(sizeof(Node));
    nd->next = NULL;
    nd->deg = d;
    nd->coeff = c;

    return nd;
}

Polynomial getPoly(int d)
{
    int c;
    Polynomial p;
    Node *last = NULL, *nd;
    p.start = NULL;

    printf("\n");
    while(d+1)
    {
        if(d)
            printf("Enter the coefficient for %d : ",d);
        else
            printf("Enter the coefficient       : ");
        scanf("%d",&c);

        if(c)
        {
            nd = makeNode(c,d);
            if(p.start==NULL)
                p.start = nd;
            else
                last->next = nd;
            last = nd;
        }
        d--;
    }
    p.degree = p.start->deg;
    return p;
}

Polynomial addPoly(Polynomial p,Polynomial q)
{
    Polynomial sum;
    Node *ptr,*qtr;
    ptr = p.start;
    qtr = q.start;
    sum.start = NULL;
    Node *last=NULL,*nd;

    while(ptr && qtr)
    {
        if(ptr->deg>qtr->deg)
        {
            nd = makeNode(ptr->coeff,ptr->deg);
            if(sum.start==NULL)
                sum.start = nd;
            else
                last->next = nd;
            last = nd;
            ptr = ptr->next;
        }
        else if(qtr->deg==ptr->deg)
        {
            if(ptr->coeff+qtr->coeff)
            {
                nd = makeNode(ptr->coeff+qtr->coeff,ptr->deg);
                if(sum.start==NULL)
                    sum.start = nd;
                else
                    last->next = nd;
                last = nd;
            }
            ptr = ptr->next;
            qtr = qtr->next;
        }
        else
        {
            nd = makeNode(qtr->coeff,qtr->deg);
            if(sum.start==NULL)
                sum.start = nd;
            else
                last->next = nd;
            last = nd;
            qtr = qtr->next;
        }
    }

    //This method is  too long  // Check the one below
    /*if(p.start)
    {
        while(p.start)
        {
            nd = makeNode(p.start->coeff,p.start->deg);
            if(sum.start==NULL)
                sum.start = nd;
            else
                last->next = nd;
            last = nd;
            p.start = p.start->next;
        }
    }

    if(q.start)
    {
        while(q.start)
        {
            nd = makeNode(q.start->coeff,q.start->deg);
            if(sum.start==NULL)
                sum.start = nd;
            else
                last->next = nd;
            last = nd;
            q.start = q.start->next;
        }
    }*/

    //Remember this technique below
    if(qtr) ptr = qtr;
    while(ptr)
        {
            nd = makeNode(ptr->coeff,ptr->deg);
            if(sum.start==NULL)
                sum.start = nd;
            else
                last->next = nd;
            last = nd;
            ptr = ptr->next;
        }

    sum.degree = sum.start->deg;
    return sum;
}

Polynomial subPoly(Polynomial p,Polynomial q)
{
    Polynomial sub;
    Node *ptr=p.start,*qtr=q.start;
    sub.start=NULL;
    Node *last=NULL,*nd;

    while(ptr && qtr)
    {
        if(ptr->deg>qtr->deg)
        {
            nd = makeNode(ptr->coeff,ptr->deg);
            if(sub.start==NULL)
                sub.start = nd;
            else
                last->next = nd;
            last = nd;
            ptr = ptr->next;
        }
        else if(qtr->deg==ptr->deg)
        {
            if(ptr->coeff-qtr->coeff)
            {
                nd = makeNode(ptr->coeff-qtr->coeff,ptr->deg);
                if(sub.start==NULL)
                    sub.start = nd;
                else
                    last->next = nd;
                last = nd;
            }
            ptr = ptr->next;
            qtr = qtr->next;
        }
        else
        {
            nd = makeNode(-qtr->coeff,qtr->deg);
            if(sub.start==NULL)
                sub.start = nd;
            else
                last->next = nd;
            last = nd;
            qtr = qtr->next;
        }
    }
    if(qtr) ptr = qtr;
    while(ptr)
        {
            nd = makeNode(ptr->coeff,ptr->deg);
            if(sub.start==NULL)
                sub.start = nd;
            else
                last->next = nd;
            last = nd;
            ptr = ptr->next;
        }

    sub.degree = sub.start->deg;
    return sub;
}

Polynomial multPoly(Polynomial p,Polynomial q)
{
    int i;
    Polynomial mult;
    mult.start=NULL;
    Node *ptr,*qtr,*nd,*last=NULL;
    for(i=(p.degree+q.degree);i>=0;i--)
    {
        nd = makeNode(0,i);
        if(mult.start==NULL)
            last = mult.start = nd;
        else
            last->next = nd;
        last = nd;
    }
    nd = mult.start;
    for(ptr=p.start;ptr;ptr=ptr->next)
    {
        for(qtr=q.start;qtr;qtr=qtr->next)
        {
            while(nd->deg!=(ptr->deg+qtr->deg))
                nd = nd->next;
            nd->coeff += (ptr->coeff)*(qtr->coeff);
        }
        nd = mult.start;
    }

    qtr = mult.start;
    ptr = qtr->next;
    while(ptr)                      //qtr can never be NULL!!
    {
        if(ptr->coeff==0)
            ptr = qtr->next = ptr->next;
        else
        {
            qtr = ptr;
            ptr = ptr->next;
        }
    }

    mult.degree = mult.start->deg;
    return mult;
}

float evalPoly(Polynomial p,float x)
{
    float eval = 0;
    printf("\n");
    while(p.start)
    {
        eval += (pow(x,(p.start->deg))*(p.start->coeff));
        p.start = p.start->next;
    }
    printf("\nThe value of Polynomial at %f is %f",x,eval);

    return eval;
}
