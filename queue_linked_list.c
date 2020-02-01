#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define MAX 4

typedef struct _queue
{
    int val;
    struct _queue *next;
}Queue;

//Initialize is front == NULL and rear == NULL
Queue *makeNode(int);
Queue *insertq(Queue*,Queue**,int);
Queue *deleteq(Queue*);
Queue *printq(Queue*);

int main()
{
    //This is initialization
    Queue *front=NULL,*rear=NULL;

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
                        front = insertq(front,&rear,n);
                        if(front)
                            printf("\n\n\n\n\n\n\t\t\t\t\tItem Inserted Successfully..  press any key");
                        else            //Never executed
                            printf("\n\n\n\n\n\n\t\t\t\t\tQueue Overflow - Insertion failed..  press any key");
                        break;
            case 'd':
            case 'D':   system("cls");
                        printf("\n\n\n\n\t\t\t\t\t\t\tQueue - Delete");
                        printf("\n\t\t\t\t\t\t\t--------------");

                        if(front==NULL)
                            printf("\n\n\n\n\n\n\t\t\t\t\tQueue Underflow - Deletion failed..  press any key");
                        else
                        {
                            printf("\n\n\n\t\t\t\t\t\t\tItem Deleted : %d",front->val);
                            front = deleteq(front);
                            printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
                        }
                        break;
            case 'p':
            case 'P':   system("cls");
                        front = printq(front);
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

Queue *makeNode(int n)
{
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->val = n;
    q->next = NULL;

    return q;
}

Queue *insertq(Queue *front,Queue **p2rear,int n)
{
    if(front==NULL)
        *p2rear = front = makeNode(n);
    else
        *p2rear = (*p2rear)->next = makeNode(n);
    return front;
}

Queue *deleteq(Queue *front)
{
    if(front)
    {
        Queue *tmp = front;
        front = front->next;
        free(tmp);
    }
    return front;
}

Queue *printq(Queue *front)
{
    printf("\n\n\n\n\n\n\n\t\t\t\t\t[ ");
    if(front==NULL)
    {
        printf("\b]");
        return NULL;
    }
    while(front)
    {
        printf("%d  ",front->val);
        front = deleteq(front);
    }
    printf("\b]\n");
    return front;
}
