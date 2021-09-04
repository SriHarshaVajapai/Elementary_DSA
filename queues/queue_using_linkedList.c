#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *next;
};

typedef struct node node;

node *front = NULL;
node *rear = NULL;

node *create_newnode(int);
void enqueue(int);
int dequeue();
void print_queue();

int main(){
    int choice, n, dqed;
    while(1){
        printf("\n*********************************\n");
        printf("Please select your choice:\n");
        printf("1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n");
        printf("*********************************\n");
        printf("Your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter value to enqueue: ");
            scanf("%d",&n);
            enqueue(n);
            break;
        case 2:
            dqed = dequeue();
            if(dqed == -1) printf("Cannot dequeue, queue is empty\n");
            else printf("%d dequeued from the queue\n",dqed);
            break;
        case 3:
            print_queue();
            break;
        case 4:
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
    return newnode;
}

void enqueue(int data){
    node *newnode = create_newnode(data);
    if(front==NULL && rear == NULL){
        front = newnode;
        rear = newnode;
    }
    else if(front != NULL){
        rear->next = newnode;
        rear = newnode;
    }
}

int dequeue(){
    if(front!=NULL && rear!=NULL){
        if(front == rear){
            node *temp = front;
            int x = temp->data;
            front = NULL;
            rear = NULL;
            free(temp);
            return x;
        }
        else{
            node *temp = front;
            int x = temp->data;
            front = front->next;
            free(temp);
            return x;
        }
        
    }
    return -1;
}

void print_queue(){
    if(front!=NULL && rear!=NULL){
        node *temp = front;
        while(temp!=NULL){
            printf("%d->",temp->data);
            temp = temp->next;
        }
    }
    printf("NULL\n");
}