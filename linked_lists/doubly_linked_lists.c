#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node*prev,*next;
};

typedef struct node node;

node *head = NULL;
node *tail = NULL;

node *create_newnode(int data);
void create_linked_list();
void print_linked_list();
void insert_node_at_beginning(int);
void insert_node_at_end(int);
void insert_node_nth_position(int,int);
void delete_node_beginning();
void delete_node_end();
void delete_nth_node(int pos);

int main(){
    create_linked_list();
    int choice,n,pos;
    while(1){
        printf("\n*********************************\n");
        printf("Please select your choice:\n");
        printf("1. Insert at beginning\n2. Insert at end\n3. Insert at nth position\n4. Delete from beginning\n5. Delete from end\n6. Delete from nth position\n7.Display list\n8. Exit\n");
        printf("*********************************\n");
        printf("Your choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d",&n);
            insert_node_at_beginning(n);
            break;
        case 2:
            printf("Enter value to insert: ");
            scanf("%d",&n);
            insert_node_at_end(n);
            break;
        case 3:
            printf("Enter the position(other than first/last): ");
            scanf("%d",&pos);
            printf("Enter value to insert: ");
            scanf("%d",&n);
            insert_node_nth_position(pos,n);
            break;
        case 4:
            delete_node_beginning();
            break;
        case 5:
            delete_node_end();
            break;
        case 6:
            printf("Enter the position to delete(neither first nor last): ");
            scanf("%d",&pos);
            delete_nth_node(pos);
            break;
        case 7:
            print_linked_list();
            break;
        case 8:
            exit(0);
        default:
            printf("\nPlease enter a valid input\n");
            break;
        }
    }
    return 0;
}

node *create_newnode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->next = NULL;
    newnode->prev = NULL;
    return newnode;
}

void create_linked_list(){
    int input;
    printf("Enter the data with -1 as terminator:\n");
    scanf("%d",&input);
    while(input != -1){
        if(head==NULL){
            head = create_newnode(input);
            tail = head;
        }
        else{
            node *newnode = create_newnode(input);
            tail->next = newnode;
            newnode->prev = tail;
            tail = newnode;
        }
        scanf("%d",&input);
    }
}

void print_linked_list(){
    node *current = head;
    printf("From HEAD to TAIL->\n  ");
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("From TAIL to HEAD->\n  ");
    current = tail ;
    while(current !=NULL){
        printf("%d->",current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void insert_node_at_beginning(int n){
    node *newnode = create_newnode(n);
    newnode->next = head;
    head->prev = newnode;
    head = newnode;
}

void insert_node_at_end(int n){
    node *newnode = create_newnode(n);
    tail->next = newnode;
    newnode->prev = tail;
    tail = newnode;
}

void insert_node_nth_position(int pos, int n){
    node *newnode = create_newnode(n);
    node *current = head;
    for(int i=1;i<pos-1;i++){
        current = current->next;
    }
    newnode->next = current->next;
    newnode->next->prev = newnode;
    newnode->prev = current;
    current->next = newnode;
}

void delete_node_beginning(){
    node *current = head;
    head = head->next;
    head->prev = NULL;
    free(current);
}

void delete_node_end(){
    node *current = tail;
    tail = tail->prev;
    tail->next = NULL;
    free(current);
}

void delete_nth_node(int pos){
    node *current = head;
    node *prev = head;
    for(int i=1;i<pos;i++){
        prev = current;
        current = current->next;
    }
    prev->next = current->next;
    current->next->prev = prev;
    free(current);
}