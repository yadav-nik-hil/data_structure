#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct
{
  int deg;
  int *coeff;
}Polynomial;

Polynomial createPoly(int);
void printPoly(Polynomial);
Polynomial addPoly(Polynomial,Polynomial,int);
Polynomial subPoly(Polynomial,Polynomial,int);
Polynomial multPoly(Polynomial,Polynomial,int);
int evalPoly(Polynomial,int);

int main()
{
    int x,eval;
    Polynomial p,q,sum,sub1,sub2,mult;

    printf("\nEnter the degree of polynomial 1 : ");
    scanf("%d",&(p.deg));
    p=createPoly(p.deg);

    printf("\nEnter the degree of polynomial 2 : ");
    scanf("%d",&(q.deg));
    q=createPoly(q.deg);

    printf("\nPolynomial 1 : \n");
    printPoly(p);

    printf("\nPolynomial 2 : \n");
    printPoly(q);

    sum.deg=p.deg>=q.deg?p.deg:q.deg;

    sum=addPoly(p,q,sum.deg);
    printf("\nAddition of Poly 1 and Poly 2 : \n");
    printPoly(sum);

    sub1.deg=sum.deg;
    sub1=subPoly(p,q,sub1.deg);
    printf("\nPoly 1 - Poly 2 : \n");
    printPoly(sub1);

    sub2.deg=sum.deg;
    sub2=subPoly(q,p,sub2.deg);
    printf("\nPoly 2 - Poly 1 : \n");
    printPoly(sub2);

    mult=multPoly(p,q,(p.deg+q.deg));
    printf("\nThe Multiplication polynomial is : \n");
    printPoly(mult);

    printf("\nEnter the value at which the Polynomial 1 is to be evaluated : ");
    scanf("%d",&x);
    eval = evalPoly(p,x);
    printf("\nThe value is : %d",eval);


    return 0;
}

Polynomial createPoly(int d)
{
    Polynomial p;
    p.deg=d;
    p.coeff = (int*)malloc(sizeof(int)*(d+1));
    printf("\n");
    while(d)
    {
        printf("Enter the coefficient for degree %d : ",d);
        scanf("%d",&p.coeff[d]);
        d--;
    }
    printf("\nEnter the constant                 : ");
    scanf("%d",&p.coeff[0]);

    return p;
}

void printPoly(Polynomial p)
{
    int first = 1;
    while(p.deg)
    {
        if(p.coeff[p.deg])
        {
            if(p.deg>1)
            {
                if(first)
                {
                    if(p.coeff[p.deg]==1)
                        printf("x^%d ",p.deg);
                    else if(p.coeff[p.deg]==-1)
                        printf("- x^%d ",p.deg);
                    else
                        printf("%dx^%d ",p.coeff[p.deg],p.deg);
                }
                else
                {
                    if(p.coeff[p.deg]==1)
                        printf(" + x^%d ",p.deg);
                    else if(p.coeff[p.deg]==-1)
                        printf(" - x^%d ",p.deg);
                    else
                        printf(" %+dx^%d ",p.coeff[p.deg],p.deg);
                }
            }
            else                                 //BTW d=1
            {
                if(first)
                {
                    if(p.coeff[1]==1)
                        printf("+ x ");
                    else if(p.coeff[1]==-1)
                        printf("- x ");
                    else
                        printf("%dx ",p.coeff[1]);
                }
                else
                {
                    if(p.coeff[1]==1)
                        printf(" + x ");
                    else if(p.coeff[1]==-1)
                        printf(" - x ");
                    else
                        printf(" %+dx ",p.coeff[1]);
                }
            }
            first = 0;
        }
        p.deg--;
    }
    if(p.coeff[0])
        {
            if(first)
                printf("%d",p.coeff[0]);
            else
                printf(" %+d",p.coeff[0]);

        }
}

Polynomial addPoly(Polynomial p,Polynomial q,int d)
{
    int i=0;
    Polynomial sum;
    sum.deg=d;
    sum.coeff = (int*)malloc(sizeof(int)*(d+1));
    while(p.deg+1 && q.deg+1)
    {
        sum.coeff[i]=p.coeff[i]+q.coeff[i];
        p.deg--;
        q.deg--;
        i++;
    }
    if(p.deg+1)
    {
        while(p.deg+1)
        {
            sum.coeff[i] = p.coeff[i];
            i++;
            p.deg--;
        }
    }
    if(q.deg+1)
    {
        while(q.deg+1)
        {
            sum.coeff[i] = q.coeff[i];
            i++;
            q.deg--;
        }
    }

    return sum;
}

Polynomial subPoly(Polynomial p,Polynomial q,int d)
{
    int i=0;
    Polynomial sub;
    sub.deg = d;
    sub.coeff = (int*)malloc(sizeof(int)*(d+1));
    while(p.deg+1 && q.deg+1)
    {
        sub.coeff[i]=p.coeff[i]-q.coeff[i];
        p.deg--;
        q.deg--;
        i++;
    }
    if(p.deg+1)
    {
        while(p.deg+1)
        {
            sub.coeff[i] = p.coeff[i];
            i++;
            p.deg--;
        }
    }
    if(q.deg+1)
    {
        while(q.deg+1)
        {
            sub.coeff[i] = -q.coeff[i];
            i++;
            q.deg--;
        }
    }

    return sub;
}

Polynomial multPoly(Polynomial p,Polynomial q,int d)
{
    int i=0,j=0,k=0;
    Polynomial mult;
    mult.deg=d;
    mult.coeff = (int*)malloc(sizeof(int)*(d+1));
    for(i;i<=d;i++)
        mult.coeff[i]=0;
    i=0;

    while(j<=p.deg)
    {
        while(i<=(p.deg+q.deg) && k<=q.deg)
        {
           mult.coeff[i++]+=(p.coeff[j]*q.coeff[k++]);
        }
        k=0;
        j++;
        i=j;
    }

    return mult;
}

int evalPoly(Polynomial p,int x)
{
    int eval=0,i=0;
    for(i=0;i<=p.deg;i++)
    {
        eval += (int)(pow(x,i)*p.coeff[i]);
    }

    return eval;
}
