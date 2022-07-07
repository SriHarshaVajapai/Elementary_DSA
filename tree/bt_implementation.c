#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node *leftchild;
    struct node *rightchild;
};

typedef struct node node;

struct node * root = NULL;

node *create_tree();
void preorder(node *root);
void postorder(node * root);
void inorder(node *root);
int depth(node *root);


int main(){
    int choice;
    root = create_tree();
    while(1){
        printf("\n*********************************\n");
        printf("Please select your choice:\n");
        printf("1. Preorder Traversal\n2. Postorder Traversal\n3. Inorder Traversal\n4. Height of the tree\n5. Exit\n");
        printf("*********************************\n");
        printf("Your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                preorder(root);
                break;
            case 2:
                postorder(root);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                printf("Depth: %d\n", depth(root));
                break;
            case 5:
                return 0;
            default:
                printf("Enter a valid number\n");
                break;
        }
    }
    return 0;
}

node *create_tree(){
    int input;
    printf("Enter the data with -1 as terminator:\n");
    scanf("%d",&input);

    if(input == -1){
        return NULL;
    }
    node *newnode = (node *)malloc(sizeof(node));
    newnode->data = input;

    printf("Enter the left child of %d:\n",input);
    newnode->leftchild = create_tree();

    printf("Enter the right child of %d:\n",input);
    newnode->rightchild = create_tree();

    return newnode;
}

void preorder(node *root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->leftchild);
        preorder(root->rightchild);
    }
}

void postorder(node *root){
    if(root!=NULL){
        postorder(root->leftchild);
        postorder(root->rightchild);
        printf("%d ",root->data);
    }
}

void inorder(node *root){
    if(root!=NULL){
        inorder(root->leftchild);
        printf("%d ",root->data);
        inorder(root->rightchild);
    }
}

int depth(node *root){
    if(root==NULL)
        return 0;
    int left_depth = depth(root->leftchild);
    int right_depth = depth(root->rightchild);
    if(left_depth>right_depth) return (left_depth+1);
    return (right_depth+1);
}