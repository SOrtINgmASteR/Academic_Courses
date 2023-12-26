#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};
//Head pointer & Size
struct node *head = NULL;
int list_size = 0;

//Insertion at Beginning
void insertion_at_beginning(int new_element)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_element;
    new_node->next = head;
    head = new_node;
    list_size++;
}

//Insertion at Ending
void insertion_at_ending(int new_element)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = new_element;
    struct node *traverse_node = head;
    if(head == NULL)
    {
        head = new_node;
        new_node->next = NULL;
    }
    else if(head != NULL)
    {
        while(traverse_node->next != NULL)
        {
            traverse_node = traverse_node->next;
        }
        traverse_node->next = new_node;
        new_node->next = NULL;
    }
    list_size++;
}

//Insertion at Any Position
void insertion_at_any_position(int new_element, int position)
{
    //0 based indexing / positioning
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *traverse_node = head;
    new_node->data = new_element;
    int traverse_position = 0;
    if(position == 0)
    {
        insertion_at_beginning(new_element);
        list_size++;
    }
    else if(position == list_size)
    {
        insertion_at_ending(new_element);
        list_size++;
    }
    else if(position > 0 && position < list_size)
    {
        while(traverse_node->next != NULL)
        {
            traverse_position++;
            if(traverse_position == position) break;
            traverse_node = traverse_node->next;
        }
        new_node->next = traverse_node->next;
        traverse_node->next = new_node;
        list_size++;
    }
    else
    {
        printf("Invalid Position\n");
    }
}

//Deletion at Beginning
void deletion_at_beginning()
{
    struct node *first_node = head;
    head = first_node->next;
    free(first_node);
    list_size--;
}

//Deletion at Ending
void deletion_at_ending()
{
    struct node *traverse_node, *previous;
    traverse_node = head;
    while(traverse_node->next != NULL)
    {
        previous = traverse_node;
        traverse_node = traverse_node->next;
    }
    previous->next = NULL;
    free(traverse_node);
    list_size--;
}

//Deletion at Any Position
void deletion_at_any_position(int position)
{
    //0 based indexing / positioning
    struct node *traverse_node = head, *previous_node;
    int traverse_position = 0;
    if(position == 0)
    {
        deletion_at_beginning();
    }
    else if(position == list_size)
    {
        deletion_at_ending();
    }
    else if(position > 0 && position < list_size)
    {
        while(traverse_node->next != NULL)
        {
            previous_node = traverse_node;
            traverse_node = traverse_node->next;
            traverse_position++;
            if(traverse_position == position) break;
        }
        previous_node->next = traverse_node->next;
        free(traverse_node);
        list_size--;
    }
    else
    {
        printf("Invalid position\n");
    }
}

//Reversal of Linked List
void reverse_linked_list()
{
    struct node *previous_node, *traversal_node, *next_node;
    previous_node = NULL;
    traversal_node = head;
    while(traversal_node != NULL)
    {
        next_node = traversal_node->next;
        traversal_node->next = previous_node;
        previous_node = traversal_node;
        traversal_node = next_node;
    }
    head = previous_node;
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
    int element, position, option;
    while(1){
        scanf("%d", &option);
        if(option == 0)break;
        switch(option){
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
                scanf("%d", &position);
                insertion_at_any_position(element, position);
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
                scanf("%d", &position);
                deletion_at_any_position(position);
                break;
            case 7:
                printf("Print Linked List : ");
                print_linked_list();
                break;
            case 8:
                printf("Reverse Linked List : ");
                reverse_linked_list();
                break;
            default :
                break;
        }
    }
    return 0;
}