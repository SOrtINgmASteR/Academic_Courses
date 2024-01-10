#include<stdio.h>
#include<stdbool.h>

int queue[1000000];
int enqueqe_index=-1;
int dequeue_index=0;

void enqueue(int push_element)
{
    enqueqe_index++;
    queue[enqueqe_index]=push_element;
}

int dequeue()
{
   int first_element, i;
   first_element = queue[dequeue_index];
   for(i=0; i<enqueqe_index; i++)
   {
        queue[i] = queue[i+1];
   }
   enqueqe_index--;
   return first_element;
}


void print_queue()
{
    int i;
    for(i=dequeue_index; i<=enqueqe_index; i++)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void reverse_print_queue()
{
    int i;
    for(i=enqueqe_index; i>=dequeue_index; i--)
    {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int current_size()
{
    int size;
    size = enqueqe_index+1;
    return size;
}

bool is_empty()
{
    if(enqueqe_index < dequeue_index) return true;
    else return false;
}

void search(int search_element)
{
    int i;
    for(i=enqueqe_index; i>=dequeue_index; i--)
    {
        if(queue[i]==search_element)
        {
            printf("%d is at %d Position\n",search_element, i+1);
        }
    }
}

int main()
{
    int i, pop_element, insert_element, option, queqe_current_size, search_element;
    while(true)
    {
        scanf("%d", &option);
        if(option==0) break;
        switch(option)
        {
            case 1:
                printf("Enter element : ");
                scanf("%d", &insert_element);
                enqueue(insert_element);
                break;
            case 2:
                pop_element=dequeue();
                printf("The last element : %d\n", pop_element);
                break;
            case 3:
                if(is_empty()==true) printf("Stack is empty\n");
                else printf("The Queue has %d elements\n", (enqueqe_index-dequeue_index)+1);
                break;
            case 4:
                queqe_current_size=current_size();
                printf("The Queue has %d elements\n", queqe_current_size);
                break;
            case 5:
                print_queue();
                break;
            case 6:
                reverse_print_queue();
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