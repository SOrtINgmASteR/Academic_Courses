//Circular Singly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};

//Tail & List size
struct node *tail = NULL;
int list_size = 0;

//Insertion at Beginning
void insertion_at_beginning(int new_element)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_element;
    if(tail != NULL)
    {
        new_node->next = tail->next;
        tail->next = new_node;
    }
    else if(tail == NULL)
    {
        tail = new_node;
        new_node->next = tail;
    }
    list_size++;
}

//Insertion at Ending
void insertion_at_ending(int new_element)
{
    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = new_element;
    if(tail != NULL)
    {
        new_node->next = tail->next;
        tail->next = new_node;
        tail = new_node;
    }
    else if(tail == NULL)
    {
        tail = new_node;
        new_node->next = tail;
    }
    list_size++;
}

//Deletion at Beginning
void deletion_at_beginning()
{
    struct node *first_node;
    if(tail == NULL)
    {
        printf("There is no elements in the linked List");
        return;
    }
    first_node = tail->next;
    tail->next = first_node->next;
    free(first_node);
    list_size--;
}

//Deletion at Ending
void deletion_at_ending()
{
    struct node *last_node, *previous_node;
    last_node = tail->next;
    do
    {
        previous_node = last_node;
        last_node = last_node->next;
    } while(last_node != tail);
    previous_node->next = tail->next;
    tail = previous_node;
    free(last_node);
    list_size--;
}

//Print or Traverse Linked List
void print_linked_list()
{
    struct node *traverse_node = tail;
    if(tail == NULL)
    {
        printf("The Linked List is Empty\n");
    }
    else
    {
        traverse_node = tail->next;
        do{
            printf("%d ", traverse_node->data);
            traverse_node = traverse_node->next;
        }while(traverse_node != tail->next);
        printf("\n");
    }
}

int main()
{
    int element, index, option;
    while(1)
    {
        scanf("%d", &option);
        if(option == 0)break;
        switch(option)
        {
            case 1:
                printf("Insertion at Beginnig, Enter Element : ");
                scanf("%d", &element);
                insertion_at_beginning(element);
                break;
            case 2:
                printf("Insertion at Ending, Enter Element : ");
                scanf("%d", &element);
                insertion_at_ending(element);
                break;
            case 3:
                break;
            case 4:
                printf("Deletion at Beginnig\n");
                deletion_at_beginning();
                break;
            case 5:
                printf("Deletion at Ending\n");
                deletion_at_ending();
                break;
            case 6:
                break;
            case 7:
                printf("Print Linked List : ");
                print_linked_list();
                break;
            default :
                break;
        }
    }
    return 0;
}