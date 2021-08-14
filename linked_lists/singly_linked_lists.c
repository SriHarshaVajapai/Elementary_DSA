/*
    Enter the data with -1 as terminator:
    2 3 5 -1
    The list: 2->3->5->NULL
    Enter the data to insert at beggining: 1
    List after inserting at beggning: 1->2->3->5->NULL
    Enter the data to insert at end: 6
    List after inserting at end: 1->2->3->5->6->NULL
    Enter the position(neither first nor last) :4
    Enter the data to insert: 4
    List after inserting at nth position :1->2->3->4->5->6->NULL
    List after deleting at beginning: 2->3->4->5->6->NULL
    List after deleting at end: 2->3->4->5->NULL
    Enter the position to delete(neither first nor last): 3
    List after deleting nth node: 2->3->5->NULL

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *create_newnode(int data);
node *create_linked_list();
void print_linked_list(node *);
node *insert_node_at_beginnig(node *);
void insert_node_at_end(node *);
void insert_node_nth_position(node *);
node *delete_node_beginning(node *);
void delete_node_end(node *);
void delete_nth_node(node *);

int main(){
    node *head = NULL;
    //create linked list
    head = create_linked_list();
    //print linked list
    printf("The list: ");
    print_linked_list(head);
    //insert node in the beginning
    head = insert_node_at_beginnig(head);
    printf("List after inserting at beggning: ");
    print_linked_list(head);
    //insert node at the end
    insert_node_at_end(head);
    printf("List after inserting at end: ");
    print_linked_list(head);
    //insert node at nth position
    insert_node_nth_position(head);
    printf("List after inserting at nth position :");
    print_linked_list(head);
    //delete at the beginning
    head = delete_node_beginning(head);
    printf("List after deleting at beginning: ");
    print_linked_list(head);
    //delete at the end
    delete_node_end(head);
    printf("List after deleting at end: ");
    print_linked_list(head);
    //delete node at nth position
    delete_nth_node(head);
    printf("List after deleting nth node: ");
    print_linked_list(head);
    return 0;
}

node *create_linked_list(){
    int input;
    node *head = NULL,*current;
    printf("Enter the data with -1 as terminator:\n");
    scanf("%d",&input);
    while(input != -1){
        if(head==NULL){
            head = create_newnode(input);
            current = head;
        }
        else{
            node *newnode = create_newnode(input);
            current->next = newnode;
            current = newnode;
        }
        scanf("%d",&input);
    }
    return head;
}

node *create_newnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
}

void print_linked_list(node *head){
    node *current = head;
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

node *insert_node_at_beginnig(node *head){
    int data;
    printf("Enter the data to insert at beggining: ");
    scanf("%d",&data);
    node *newnode = create_newnode(data);
    newnode->next = head;
    head = newnode;
    return head;
}

void insert_node_at_end(node *head){
    int data;
    printf("Enter the data to insert at end: ");
    scanf("%d",&data);
    node *newnode = create_newnode(data);
    node *current = head;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newnode;
}

void insert_node_nth_position(node *head){
    int position,data;
    printf("Enter the position(neither first nor last) :");
    scanf("%d",&position);
    printf("Enter the data to insert: ");
    scanf("%d",&data);
    node *newnode = create_newnode(data);
    node *current = head;
    for(int i=1;i<position-1;i++){
        current = current->next;
    }
    newnode->next = current->next;
    current->next = newnode;
}

node *delete_node_beginning(node *head){
    node *current = head;
    head = head->next;
    free(current);
    return head;
}

void delete_node_end(node *head){
    node *current = head;
    node *prev = head;
    while(current->next != NULL){
        prev = current;
        current = current->next;
    }
    prev->next = NULL;
    free(current);
}

void delete_nth_node(node *head){
    node *current = head;
    node *prev = head;
    int position;
    printf("Enter the position to delete(neither first nor last): ");
    scanf("%d",&position);
    for(int i=1;i<position;i++){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    free(current);
}