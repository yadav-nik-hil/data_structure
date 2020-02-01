#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int *createPoly(int);
void printPoly(int*,int);
int *addPoly(int*,int*,int,int,int);
int *subPoly(int*,int*,int,int,int);
int *multPoly(int*,int*,int,int,int);
int evalPoly(int*,int,int);

int main()
{
    int d1,d2,d3,eval,x;
    int*p,*q,*sum,*sub,*sub_,*mult;

    printf("\nEnter the degree of polynomial 1 : ");
    scanf("%d",&d1);
    p=createPoly(d1);

    printf("\nEnter the degree of polynomial 2 : ");
    scanf("%d",&d2);
    q=createPoly(d2);

    printf("\nPolynomial 1 : \n");
    printPoly(p,d1);
    printf("\n");

    printf("\nPolynomial 2 : \n");
    printPoly(q,d2);

    if(d1>=d2)
        d3=d1;
    else
        d3=d2;

    sum=addPoly(p,q,d1,d2,d3);
    printf("\nAddition of Poly 1 and Poly 2 : \n");
    printPoly(sum,d3);

    sub=subPoly(p,q,d1,d2,d3);
    printf("\nPoly 1 - Poly 2 : \n");
    printPoly(sub,d3);

    sub_=subPoly(q,p,d2,d1,d3);
    printf("\nPoly 2 - Poly 1 : \n");
    printPoly(sub_,d3);

    mult=multPoly(p,q,d1,d2,(d1+d2));
    printf("\nThe Multiplication polynomial is : \n");
    printPoly(mult,(d1+d2));

    printf("\nEnter the value at which you want to evaluate Polynomial 1  : ");
    scanf("%d",&x);
    eval=evalPoly(p,d1,x);
    printf("The value is : %d",eval);



    return 0;
}

int *createPoly(int d)
{
    int*p;
    p = (int*)malloc(sizeof(int)*(d+1));
    printf("\n");
    while(d)
    {
        printf("Enter the coefficient for degree %d : ",d);
        scanf("%d",&p[d]);
        d--;
    }
    printf("\nEnter the constant                  : ");
    scanf("%d",&p[0]);

    return p;
}

void printPoly(int *p,int d)
{
    int first = 1;
    while(d)
    {
        if(p[d])
        {
            if(d>1)
            {
                if(first)
                {
                    if(p[d]==1)
                        printf("x^%d ",d);
                    else if(p[d]==-1)
                        printf("- x^%d ",d);
                    else
                        printf("%dx^%d ",p[d],d);
                }
                else
                {
                    if(p[d]==1)
                        printf(" + x^%d ",d);
                    else if(p[d]==-1)
                        printf(" - x^%d ",d);
                    else
                        printf(" %+ dx^%d ",p[d],d);
                }
            }
            else                                 //BTW d=1
            {
                if(first)
                {
                    if(p[1]==1)
                        printf("+ x ");
                    else if(p[1]==-1)
                        printf("- x ");
                    else
                        printf("%dx ",p[1]);
                }
                else
                {
                    if(p[1]==1)
                        printf(" + x ");
                    else if(p[1]==-1)
                        printf(" - x ");
                    else
                        printf(" %+dx ",p[1]);
                }
            }
            first = 0;
        }
        d--;
    }
    if(p[0])
        {
            if(first)
                printf("%d",p[0]);
            else
                printf(" %+d",p[0]);

        }
}

int *addPoly(int* p,int* q,int d1,int d2,int d3)
{
    int i=0;
    int *n;
    n = (int*)malloc(sizeof(int)*(d3+1));
    while(d1+1 && d2+1)
    {
        n[i]=p[i]+q[i];
        d1--;
        d2--;
        i++;
    }
    if(d1+1)
    {
        while(d1+1)
        {
            n[i]=p[i];
            i++;
            d1--;
        }
    }
    if(d2+1)
    {
        while(d2+1)
        {
            n[i]=q[i];
            i++;
            d2--;
        }
    }

    return n;
}

int *subPoly(int*p,int*q,int d1,int d2,int d3)
{
    int i=0;
    int *m;
    m=(int*)malloc(sizeof(int)*(d3+1));
    while(d1+1 && d2+1)
    {
        m[i]=p[i]-q[i];
        d1--;
        d2--;
        i++;
    }
    if(d1+1)
    {
        while(d1+1)
        {
            m[i]=p[i];
            i++;
            d1--;
        }
    }
    if(d2+1)
    {
        while(d2+1)
        {
            m[i]=-q[i];
            i++;
            d2--;
        }
    }

    return m;
}

int *multPoly(int*p,int*q,int d1,int d2,int d4)
{
    int i=0,j=0,k=0;
    int *mult;
    mult = (int*)malloc(sizeof(int)*(d4+1));
    for(i;i<=d4;i++)
        mult[i]=0;
    i=0;

    while(j<=d1)
    {
        while(i<=(d1+d2) && k<=d2)
        {
           mult[i++]+=(p[j]*q[k++]);
        }
        k=0;
        j++;
        i=j;
    }

    return mult;
}

int evalPoly(int *p,int d,int x)
{
    int i,eval=0;
    for(i=0;i<=d;i++)
    {
        eval += (int)(pow(x,i)*(p[i]));
    }

    return eval;
}
