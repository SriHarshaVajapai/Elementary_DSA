#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

typedef struct node node;

node * root = NULL;

node *create_tree(int *,int,int);
void preorder(node *root);

int main(){
    int n;
    printf("Enter the no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    root = create_tree(arr,n,0);
    printf("Preorder traversal: ");
    preorder(root);
    return 0;
}

node *create_tree (int *arr, int n, int i){
    if(i<n){
        node *newnode = (node *)malloc(sizeof(node));
        newnode->data = arr[i];
        newnode->leftchild = create_tree(arr,n,2*i+1);
        newnode->rightchild= create_tree(arr,n,2*i+2);
        return newnode;
    }
    return NULL;
}

void preorder(node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}