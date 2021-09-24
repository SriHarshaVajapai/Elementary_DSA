#include <stdio.h>
#include <stdlib.h>

struct node{
    int data,priority;
};

struct Queue{
    int heap_size,capacity;
    struct node *arr;
};

struct Queue *create_queue(int);
void enqueue(struct Queue *, int data, int priority);
int dequeue(struct Queue *);
void print_queue(struct Queue *);
void insert_data(struct Queue *, int data, int priority);
void build_max_heap(struct Queue *);
void max_heapify(struct Queue *q, int i);
int extract_max(struct Queue *q);
void swap(struct node *, struct node *);

int main(){
    struct Queue *q;
    int capacity;
    printf("Enter the capacity of Queue: ");
    scanf("%d",&capacity);
    q=create_queue(capacity+1);
    int choice, dqed, priority, n;
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
            printf("Enter value and priority to enqueue: ");
            scanf("%d %d", &n, &priority);
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
            printf("***Since we are using heap, Printing the queue may lead to unexpected output***\n"); 
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
    q->heap_size = 0;
    q->capacity = capacity;
    q->arr = (struct node *)malloc(capacity * sizeof(struct node));
    return q;
}

void enqueue(struct Queue *q, int data, int priority){
    if(q->heap_size==q->capacity-1){
        printf("Queue is full. Cannot enqueue\n");
        return;
    }
    else{
        q->heap_size++;
        insert_data(q,data,priority);
        build_max_heap(q);
    }
}

int dequeue(struct Queue *q){
    if(q->heap_size==0) return -1;
    else{
        int re = extract_max(q);
        return re;
    }
}

void print_queue(struct Queue *q){
    if(q->heap_size!=0){
        int current = 1;
        while(current<=q->heap_size){
            printf("%d->",q->arr[current].data);
            current++;
        }
    }
    printf("NULL\n");
}

void insert_data(struct Queue *q, int data, int priority){
    q->arr[q->heap_size].data = data;
    q->arr[q->heap_size].priority = priority;
}

void build_max_heap(struct Queue *q){
    int heap_size = q->heap_size;
    for(int i=heap_size/2;i>=1;i--){
        max_heapify(q,i);
    }
}

void max_heapify(struct Queue *q, int i){
    int heap_size = q->heap_size;
    int left_child=2*i;
    int right_child=2*i+1;
    int largest;
    
    if(left_child<=heap_size && q->arr[left_child].priority>q->arr[i].priority) largest=left_child;
    else largest=i;

    if(right_child<=heap_size && q->arr[right_child].priority>q->arr[largest].priority) largest=right_child;

    if(largest!=i){
        swap(&q->arr[i],&q->arr[largest]);
        max_heapify(q,largest);
    }
}

int extract_max(struct Queue *q){
    int re = q->arr[1].data;
    q->arr[1] = q->arr[q->heap_size--];
    build_max_heap(q);
    return re;
}

void swap(struct node *a, struct node *b){
    struct node temp = *a;
    *a = *b;
    *b = temp;
}