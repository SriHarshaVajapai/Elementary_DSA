/*
    SAMPLE INPUT/OUTPUT
    
    5
    43 64 32 74 75
    75 74 64 43 32
*/

#include <stdio.h>
#include <stdlib.h>

struct Stack{
    int top;
    int capacity;
    int *arr;
};

typedef struct Stack stack;

stack *createStack(int capacity);
void push(stack *, int );
int pop(stack *);
void displayStack(stack *);
void sortStack(stack *);
void sortedInsert(stack *, int);

int main(){
    int capacity;
    scanf("%d",&capacity);
    stack *stack = createStack(capacity);
    for(int i=0;i<capacity;i++){
        int data;
        scanf("%d",&data);
        push(stack,data);
    }
    sortStack(stack);
    displayStack(stack);
    return 0;
}

stack *createStack(int capacity){
    stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->top = -1;
    stack->capacity = capacity;
    stack->arr = (int *)malloc(capacity * sizeof(int));
    return stack;
}

void push(stack *stack, int item){
    if(stack->top == stack->capacity-1) return;
    else{
        stack->arr[++stack->top] = item;
    }
}

int pop(stack *stack){
    if(stack->top != -1){
        int data = stack->arr[stack->top--];
        return data;
    } 
}

void sortStack(stack *stack){
    if(stack->top != -1){
        int temp = pop(stack);
        sortStack(stack);
        sortedInsert(stack,temp);
    }
}

void sortedInsert(stack *stack, int item){
    if(stack->top == -1 || stack->arr[stack->top]<item){
        push(stack,item);
    }
    else{
        int temp = pop(stack);
        sortedInsert(stack,item);
        push(stack,temp);
    }
}

void displayStack(stack *stack){
    int tempTop = stack->top;
    while(tempTop != -1){
        printf("%d ",stack->arr[tempTop--]);
    }
}