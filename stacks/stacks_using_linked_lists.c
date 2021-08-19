/*
    EXPLANATION:
        Input:
            ->First line contains an integer Q denoting the number of queries
            ->Second line contains Q queries separated by space
        Output:
            ->Pop and print the element in a new line whenever the query asks to pop an element from the stack. Print -1 if the stack is empty.
            ->There is a new line at the end of the output.
        Explanation:
            ->A Query Q is of 2 Types:
            ->(i) 1 x(a query of this type means pushing 'x' into the stack).
            ->(ii) 2(a query of this type means to pop an element from the stack and print the popped element).
    
    
    SAMPLE INPUT:
    5
    1 2 1 3 2 1 4 2
    OUTPUT:
    3
    4

*/

#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *link;
};

typedef struct node node;

node *top = NULL;

node *createNode(int data);
void push(int data);
int pop();

int main(){
    int capacity;
    scanf("%d",&capacity);
    for(int i=0;i<capacity;i++){
        int query;
        scanf("%d",&query);
        if(query==1){
            int x;
            scanf("%d",&x);
            push(x);
        }
        else if(query == 2){
            printf("%d\n",pop());
        }
    }
    return 0;
}

node *createNode(int data){
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = data;
    newnode->link = NULL;
    return newnode;
}

void push(int data){
    node *newnode = createNode(data);
    newnode->link = top;
    top = newnode;
}

int pop(){
    if(top != NULL){
        node *temp = top;
        top = top->link;
        int x = temp->data;
        temp->link = NULL;
        free(temp);
        return x;
    }
    return -1;
}