//Doubly Linked List
#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *prev;
    struct node *next;
};

//Head & List size
struct node *head = NULL;
int list_size = 0;

//Insertion at Beginning
void insertion_at_beginning(int new_element)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->prev = NULL;
    new_node->data = new_element;
    new_node->next = head;
    head = new_node;
    list_size++;
}

//Insertion at Ending
void insertion_at_ending(int new_element)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    struct node *traverse_node = head;
    new_node->data = new_element;
    if(head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
        new_node->next = NULL;
    }
    else if(head != NULL)
    {
        while(traverse_node->next != NULL)
        {
            traverse_node = traverse_node->next;
        }
        new_node->prev = traverse_node;
        traverse_node->next = new_node;
        new_node->next = NULL;
    }
    list_size++;
}

//Insertion at Any Position
void insertion_at_any_position(int new_element, int position)
{
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = new_element;
    struct node *traverse_node = head, *previous_node;
    int traverse_index = 0;

    if(position == 0)
    {
        insertion_at_beginning(new_element);
    }
    else if(position == list_size)
    {
        insertion_at_ending(new_element);
    }
    else if(position > 0 && position < list_size)
    {
        while(traverse_node->next != NULL)
        {
            previous_node = traverse_node;
            traverse_node = traverse_node->next;
            traverse_index++;
            if(traverse_index == position) break;
        }
        new_node->next = traverse_node;
        traverse_node->prev = new_node;
        new_node->prev = previous_node;
        previous_node->next = new_node;
        list_size++;
    }
}

//Deletion at Beginning
void deletion_at_beginning()
{
    struct node *first_node;
    first_node = head;
    head = first_node->next;
    head->prev = NULL;
    free(first_node);
    list_size--;
}

//Deletion at Ending
void deletion_at_ending()
{
    struct node *last_node = head, *previous_node;
    while(last_node->next != NULL)
    {
        previous_node = last_node;
        last_node = last_node->next;
    }
    previous_node->next = NULL;
    free(last_node);
    list_size--;
}

//Deletion at any Position
void deletion_at_any_Position(int index)
{
    if(index == 0)
    {
        deletion_at_beginning();
    }
    else if(index == list_size - 1)
    {
        deletion_at_ending();
    }
    else if(index > 0 && index < list_size - 2)
    {
        struct node *previous_node, *delete_node = head, *next_node;
        int traverse_position = 0;
        while(delete_node->next != NULL)
        {   
            previous_node = delete_node;
            delete_node = delete_node->next;
            next_node = delete_node->next;
            traverse_position++;
            if(traverse_position == index) break;
        }
        previous_node->next = next_node;
        next_node->prev = previous_node;
        free(delete_node);
        list_size--;
    }
}

//Print or Traverse Linked List
void print_linked_list()
{
    struct node *traverse_node = head;
    if(traverse_node == NULL)
    {
        printf("Linked List is empty");
    }
    else
    {
        while(traverse_node != NULL)
        {
            printf("%d ", traverse_node->data);
            traverse_node = traverse_node->next;
        }
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
                printf("Insertion at any Index, Enter Element : ");
                scanf("%d", &element);
                printf("Enter Index : ");
                scanf("%d", &index);
                insertion_at_any_position(element, index);
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
                printf("Deletion at any Index\n");
                printf("Enter Index : ");
                scanf("%d", &index);
                deletion_at_any_Position(index);
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