#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Stack{
    int capacity;
    int top;
    int *arr;
};

struct Stack *create_stack(int capacity);
void push(struct Stack *stack, int item);
int pop(struct Stack *);
int peek(struct Stack *);
int isEmpty(struct Stack *);
int isFull(struct Stack *);

int main(){
    struct Stack *stack;
    int capacity;
    scanf("%d",&capacity);
    stack = create_stack(capacity);
    //push the entered elements to the stack
    for(int i=0;i<capacity;i++){
        int temp;
        scanf("%d",&temp);
        push(stack,temp);
    }
    //pop all the elements in the stack
    while(1){
        int popped = pop(stack);
        if(popped == -1) break;
        else printf("%d ",popped);
    }
    return 0;
}

struct Stack *create_stack(int capacity){
    struct Stack *stack = (struct Stack *)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->arr = (int *)malloc(stack->capacity * sizeof(int));
    return stack;
}

void push(struct Stack *stack, int item){
    if(stack->top == stack->capacity-1) return;
    else{
        stack->top++;
        stack->arr[stack->top] = item;
    }
}

int pop(struct Stack *stack){
    if(stack->top == -1) return -1;
    else{
        int x = stack->arr[stack->top--];
        return x;
    }
}

int isEmpty(struct Stack *stack){
    return stack->top == -1;
}

int peek(struct Stack *stack){
    if(!isEmpty(stack)){
        return stack->arr[stack->top];
    }
}

int isFull(struct Stack *stack){
    return stack->top == stack->capacity-1;
}