#include <stdio.h>
#include <stdlib.h>
#include<math.h>

#define MAX 4

typedef struct _stack
{
    int top;
    int items[MAX];
}Stack;

void initialize(Stack*);
int push(Stack*,int);
int pop(Stack*);
void prints(Stack*);

int main()
{
    Stack s;

    initialize(&s);

    while(1)
    {
        system("cls");
        printf("\n\n\n\n\n\t\t\t\t\t\t  S T A C K");
        printf("\n\t\t\t\t\t\t  ---------\n");

        printf("\n\t\t\t\t\t\t[I]nsert Item");
        printf("\n\t\t\t\t\t\t[D]elete Item");
        printf("\n\t\t\t\t\t\t[P]rint Stack");
        printf("\n\t\t\t\t\t\t[Q]uit");

        printf("\n\n\n\t\t\t\t\t\tEnter Option : ");

        char opt = getchar();
        fflush(stdin);

        int n;
        switch(opt)
        {
            case 'i':
            case 'I':   system("cls");
                        printf("\n\n\n\n\t\t\t\t\t\t    Stack - Push");
                        printf("\n\t\t\t\t\t\t    ------------");
                        printf("\n\n\n\t\t\t\t\t\tEnter Item to Insert : ");
                        scanf("%d",&n);
                        fflush(stdin);
                        if(push(&s,n))
                            printf("\n\n\n\n\n\n\t\t\t\t\tItem Pushed Successfully..  press any key");
                        else
                            printf("\n\n\n\n\n\n\t\t\t\t\tStack Overflow - Push failed..  press any key");
                        break;
            case 'd':
            case 'D':   system("cls");
                        printf("\n\n\n\n\t\t\t\t\t\t\tStack - Pop");
                        printf("\n\t\t\t\t\t\t\t-----------");

                        n = pop(&s);
                        if(n==-999)
                        printf("\n\n\n\n\n\n\t\t\t\t\tStack Underflow - Pop failed..  press any key");
                        else
                        {
                            printf("\n\n\n\t\t\t\t\t\t\tItem Popped : %d",n);
                            printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
                        }
                        break;
            case 'p':
            case 'P':   system("cls");
                        prints(&s);
                        printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
                        break;
            case 'q':
            case 'Q':   exit(0);

            default :   printf("\n\n\n\n\n\n\t\t\t\t\tInvalid option.. press any key..");
        }
        getch();
        fflush(stdin);
    }

    return 0;
}

void initialize(Stack *s)
{
    s->top = -1;
}

int push(Stack *s,int n)
{
    if(s->top==MAX-1)
        return 0;
    else
        s->items[++s->top] = n;
        return 1;
}

int pop(Stack *s)
{
    if(s->top==-1)
        return -999;
    else
        return s->items[s->top--];
}

void prints(Stack *s)
{
    int i;
    while(i = pop(s))
    {
        if(i==-999)
            break;
        printf("\n\t\t\t\t\t\t\t%d",i);
    }
}
