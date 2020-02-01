#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define MAX 4
//Here one cell will be padded, so keep the MAX one extra.
typedef struct
{
    int front,rear;
    int items[MAX];
}Queue;
//Every operation is done using only delete and insert
void initialize(Queue*);
int insertq(Queue*,int);
int deleteq(Queue*);
void printq(Queue*);

void main()
{
    Queue q;

    initialize(&q);

    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\t  Q U E U E");
        printf("\n\t\t\t\t\t\t  ---------\n");

        printf("\n\t\t\t\t\t\t[I]nsert Item");
        printf("\n\t\t\t\t\t\t[D]elete Item");
        printf("\n\t\t\t\t\t\t[P]rint Queue");
        printf("\n\t\t\t\t\t\t[Q]uit");

        printf("\n\n\n\t\t\t\t\t\tEnter Option : ");

        char opt = getchar();
        fflush(stdin);

        int n;
        switch(opt)
        {
            case 'i':
            case 'I':   system("cls");
                        printf("\n\n\n\n\t\t\t\t\t\t    Queue - Insert");
                        printf("\n\t\t\t\t\t\t    --------------");
                        printf("\n\n\n\t\t\t\t\t\tEnter Item to Insert : ");
                        scanf("%d",&n);
                        fflush(stdin);
                        if(insertq(&q,n))
                            printf("\n\n\n\n\n\n\t\t\t\t\tItem Inserted Successfully..  press any key");
                        else
                            printf("\n\n\n\n\n\n\t\t\t\t\tQueue Overflow - Insertion failed..  press any key");
                        break;
            case 'd':
            case 'D':   system("cls");
                        printf("\n\n\n\n\t\t\t\t\t\t\tQueue - Delete");
                        printf("\n\t\t\t\t\t\t\t--------------");

                        n = deleteq(&q);
                        if(n==-999)
                        printf("\n\n\n\n\n\n\t\t\t\t\tQueue Underflow - Deletion failed..  press any key");
                        else
                        {
                            printf("\n\n\n\t\t\t\t\t\t\tItem Deleted : %d",n);
                            printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
                        }
                        break;
            case 'p':
            case 'P':   system("cls");
                        printq(&q);
                        printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
                        break;
            case 'q':
            case 'Q':   exit(0);

            default :   printf("\n\n\n\n\n\n\t\t\t\t\tinvalid option.. press any key..");
        }
        getch();
        fflush(stdin);
    }
}

void initialize(Queue *p)
{
    p->front = MAX-1;
    p->rear = MAX-1;
}

int insertq(Queue *p,int n)
{
    if(p->rear==MAX-1)
        p->rear = 0;
    else
        p->rear++;
    if(p->rear==p->front)
    {
        if(p->rear==0)
            p->rear = MAX-1;
        else
            p->rear--;
        return 0;
    }
    else
        p->items[p->rear] = n;

    return 1;
}

int deleteq(Queue *p)
{
    if(p->rear==p->front)
        return -999;
    else
    {
        if(p->front==MAX-1)
            p->front = 0;
        else
            p->front++;
        return p->items[p->front];
    }
}

void printq(Queue *p)
{
    int i;
    while(i = deleteq(p))
    {
        if(i==-999)
            break;
        printf("\n\t\t\t\t\t\t%d",i);
    }
}
