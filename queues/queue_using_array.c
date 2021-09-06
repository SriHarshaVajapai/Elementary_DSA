#include <stdio.h>
#include <stdlib.h>

struct Queue{
    int capacity,front,rear;
    int *arr;
};


struct Queue *create_queue(int capacity);
void enqueue(struct Queue*, int item);
int dequeue(struct Queue*);
void print_queue(struct Queue*);


int main(){
    struct Queue *q;
    int capacity;
    printf("Enter the capacity of Queue: ");
    scanf("%d",&capacity);
    q = create_queue(capacity);
    int choice, n, dqed;
    while (1)
    {
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
            scanf("%d", &n);
            enqueue(q,n);
            break;
        case 2:
            dqed = dequeue(q);
            if (dqed == -1)
                printf("Cannot dequeue, queue is empty\n");
            else
                printf("%d dequeued from the queue\n", dqed);
            break;
        case 3:
            print_queue(q);
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

struct Queue *create_queue(int capacity){
    struct Queue *q = (struct Queue*)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->capacity * sizeof(int));
    return q;
}

void enqueue(struct Queue *q, int item){
    if(q->rear == q->capacity-1){
        printf("Queue if full. Cannot enqueue\n");
        return;
    }
    else{
        if(q->front==-1 && q->rear==-1){
            q->front=0;
            q->rear=0;
            q->arr[q->rear] = item;
        }
        else if(q->front != -1){
            q->rear++;
            q->arr[q->rear] = item;
        }
    }
}

int dequeue(struct Queue *q){
    if((q->front > q->rear) || (q->front==-1 && q->rear==-1)) return -1;
    else{
        if(q->front==q->rear){
            int temp = q->arr[q->front];
            q->front = -1;
            q->rear = -1;
            return temp;
        }
        else{
            int temp = q->arr[q->front];
            q->front++;
            return temp;
        }
    }
}

void print_queue(struct Queue *q){
    if ((q->front != -1 && q->rear != -1)){
        int temp = q->front;
        while (temp <= q->rear)
        {
            printf("%d->", q->arr[temp]);
            temp++;
        }
    }
    printf("NULL\n");
}