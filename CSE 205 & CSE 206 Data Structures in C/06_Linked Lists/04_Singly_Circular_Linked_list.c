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
    insertion_at_beginning(10);
    insertion_at_beginning(12);
    insertion_at_beginning(14);
    insertion_at_beginning(16);
    print_linked_list();
    insertion_at_ending(50);
    insertion_at_ending(52);
    insertion_at_ending(54);
    print_linked_list();
    insertion_at_beginning(41);
    insertion_at_beginning(42);
    insertion_at_beginning(43);
    insertion_at_beginning(44);
    print_linked_list();
    insertion_at_ending(75);
    insertion_at_ending(80);
    insertion_at_ending(90);
    print_linked_list();
    return 0;
}