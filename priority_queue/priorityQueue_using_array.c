#include <stdio.h>
#include <stdlib.h>

struct node{
    int data,priority;
};

struct Queue{
    int capacity,front,rear;
    struct node *arr;
};

struct Queue *create_queue(int capacity);
void enqueue(struct Queue *q, int n, int priority);
int dequeue(struct Queue *q);
void shift(struct node *arr, int pos, int rear);
void swap(struct node **, struct node **);
int find_pos_to_insert(struct Queue *q,int priority);
void print_queue(struct Queue *q);

int main()
{
    struct Queue *q;
    int capacity;
    printf("Enter the capacity of Queue: ");
    scanf("%d",&capacity);
    q = create_queue(capacity);
    int choice,dqed,priority,n;
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
            enqueue(q, n, priority);
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
    struct Queue *q = (struct Queue *)malloc(sizeof(struct Queue));
    q->capacity = capacity;
    q->front = -1;
    q->rear = -1;
    q->arr = (struct node *) malloc(q->capacity *sizeof(struct node));
    return q;
}

void enqueue(struct Queue *q, int data, int priority){
    if(q->rear==q->capacity-1){
        printf("Queue is full. Cannot enqueue\n");
        return;
    }
    else{
        if(q->front==-1 && q->rear==-1){
            q->front=0;
            q->rear=0;
            q->arr[q->rear].data = data;
            q->arr[q->rear].priority = priority;
        }
        else if(q->front!=-1){
            if (priority > q->arr[q->front].priority){
                shift(q->arr,q->front,q->rear);
                q->rear++;
                q->arr[q->front].data = data;
                q->arr[q->front].priority = priority;
            }
            else if (priority < q->arr[q->rear].priority){
                q->rear++;
                q->arr[q->rear].data=data;
                q->arr[q->rear].priority=priority;
            }
            else{
                int insert_pos = find_pos_to_insert(q,priority);
                shift(q->arr,insert_pos+1,q->rear);
                q->rear++;
                insert_pos++;
                q->arr[insert_pos].data=data;
                q->arr[insert_pos].priority=priority;
            }
        }
    }
}

void shift(struct node *arr,int pos,int rear){
    int start=rear+1;
    for(int i=start;i>=pos;i--){
        arr[i]=arr[i-1];
    }
}

void print_queue(struct Queue *q){
    if(q->front!=-1 && q->rear!=-1){
        int current = q->front;
        while (current <= q->rear)
        {
            printf("%d->", q->arr[current]);
            current++;
        }
    }
    printf("NULL\n");
}

int find_pos_to_insert(struct Queue *q,int priority){
    int current = q->front;
    while(current <= q->rear){
        if(priority<=q->arr[current].priority && priority>q->arr[current+1].priority) break;
        current++;
    }
    return current;
}

int dequeue(struct Queue *q){
    if(q->front==-1 && q->rear==-1) return -1;
    else if(q->front!=-1 && q->rear!=-1){
        int re = q->arr[q->front].data;
        if(q->front == q->rear){   
            q->front=-1;
            q->rear=-1;
        }
        else{
            q->front++;
        }
        return re;
    }
}