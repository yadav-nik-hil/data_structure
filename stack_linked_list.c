#include <stdio.h>
#include <stdlib.h>
#include<math.h>

typedef struct _node
{
    int val;
    struct _node *next;
}Stack;

Stack *makeNode(int);
Stack *push(Stack*,int);
Stack *pop(Stack*);
Stack *prints(Stack*);

int main()
{
    Stack *top=NULL;

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
                        top = push(top,n);
                        if(top)
                            printf("\n\n\n\n\n\n\t\t\t\t\tItem Pushed Successfully..  press any key");
                        else         //Never Executed
                            printf("\n\n\n\n\n\n\t\t\t\t\tStack Overflow - Push failed..  press any key");
                        break;
            case 'd':
            case 'D':   system("cls");
                        printf("\n\n\n\n\t\t\t\t\t\t\tStack - Pop");
                        printf("\n\t\t\t\t\t\t\t-----------");

                        if(top==NULL)
                            printf("\n\n\n\n\n\n\t\t\t\t\tStack Underflow - Pop failed..  press any key");
                        else
                        {
                            printf("\n\n\n\t\t\t\t\t\t\tItem Popped : %d",top->val);
                            top = pop(top);
                            printf("\n\n\n\n\n\t\t\t\t\t\t\tpress any key..");
                        }
                        break;
            case 'p':
            case 'P':   system("cls");
                        top = prints(top);
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

Stack *makeNode(int n)
{
    Stack *s = (Stack*)malloc(sizeof(Stack));
    s->val = n;
    s->next = NULL;

    return s;
}

Stack *push(Stack *top,int n)
{
    Stack *nd = makeNode(n);
    if(top)
        nd->next = top;
    return nd;
}

Stack *pop(Stack *top)
{
    if(top)
    {
        Stack *tmp = top;
        top = top->next;
        free(tmp);
    }
    return top;
}

Stack *prints(Stack *top)
{
    while(top)
    {
        printf("\n\t\t\t\t\t\t\t%d",top->val);
        top = pop(top);
    }
    return top;        //top = NULL
}
