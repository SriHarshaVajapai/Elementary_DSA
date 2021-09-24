#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    int priority;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

struct node *createNode(int data, int priority);
void insert(int data, int priority);
int dequeue();
struct node *find_pos_to_insert(int priority);
void print_queue();

int main(){
    int n,choice,dqed,priority;
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
            printf("Enter value and priority to enqueue: ");
            scanf("%d %d", &n,&priority);
            insert(n,priority);
            break;
        case 2:
            dqed = dequeue();
            if (dqed == -1)
                printf("Cannot dequeue, queue is empty\n");
            else
                printf("%d dequeued from the queue\n", dqed);
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

struct node *createNode(int data, int priority){
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->data = data;
    newnode->priority = priority;
    newnode->next = NULL;
    return newnode;
}

void insert(int data, int priority){
    struct node *newnode = createNode(data, priority);
    if(front==NULL && rear==NULL){
        front=newnode;
        rear=newnode;
    }
    else if(front != NULL){
        struct node *insert_pos;
        if (priority > front->priority){
            newnode->next = front;
            front = newnode;
        }
        else if (priority < rear->priority){
            rear->next = newnode;
            rear = newnode;
        }
        else{
            insert_pos = find_pos_to_insert(priority);
            newnode->next = insert_pos->next;
            insert_pos->next = newnode;
        }
    }
}

struct node *find_pos_to_insert(int priority){
    struct node *current = front;
    while (current != NULL)
    {
        if (priority <= current->priority && priority > current->next->priority) break;
        current = current->next;
    }
    return current;
}

void print_queue(){
    struct node *current = front;
    while(current != NULL){
        printf("%d->",current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int dequeue(){
    if(front==NULL && rear==NULL) return -1;
    else if(front!=NULL && rear!=NULL){
        struct node *temp = front;
        int data = temp->data;
        if(front==rear){
            front=NULL;
            rear=NULL;
        }
        else{
            front=front->next;
        }
        free(temp);
        return data;
    }
}