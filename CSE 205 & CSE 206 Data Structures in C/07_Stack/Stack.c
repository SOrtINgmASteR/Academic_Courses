#include<stdio.h>
#include<stdbool.h>

int stack[10000000];
int top=-1;

void push(int push_element)
{
    top++;
    stack[top]=push_element;
}

int pop()
{
    int last_element;
    last_element = stack[top];
    top--;
    return last_element;
}

bool is_empty()
{
    if (top==-1) return true;
    else return false;
}

int current_size()
{
    return top+1;
}

void print_stack()
{
    int i;
    for(i=0; i<=top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void reverse_print_stack()
{
    int i;
    for(i=top; i>=0; i--)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void search(int search_element)
{
    int i;
    for(i=top; i>=0; i--)
    {
        if(stack[i] == search_element)
        {
            printf("%d is at %d Position\n", search_element, i+1);
            break;
        }
    }
}

int main()
{
    int i, pop_element, insert_element, option, stack_current_size, search_element;
    while(true)
    {
        scanf("%d", &option);
        if(option==0) break;
        switch(option)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d", &insert_element);
                push(insert_element);
                break;
            case 2:
                pop_element=pop();
                printf("The last element : %d\n", pop_element);
                break;
            case 3:
                if(is_empty()==true) printf("Stack is empty\n");
                else printf("The stack has %d elements\n", top+1);
                break;
            case 4:
                stack_current_size=current_size();
                printf("The Stack has %d elements\n", stack_current_size);
                break;
            case 5:
                print_stack();
                break;
            case 6:
                reverse_print_stack();
                break;
            case 7:
                printf("Enter search element : ");
                scanf("%d", &search_element);
                search(search_element);
                break;
            default:
                break;
        }
    }
    return 0;
}