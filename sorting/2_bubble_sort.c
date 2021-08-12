#include <stdio.h>

void bubble_sort(int *);
void swap(int *, int *);
void print_arr(int *);

int main(){
    int arr[10];
    printf("Enter array of length 10: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    bubble_sort(arr);
    print_arr(arr);
    return 0;
}

void bubble_sort(int *arr){
    int n=10;
    for(int i=0;i<n;i++){
        char swapped = 0;
        for(int j=0;j<=n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j],&arr[j+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b =temp;
}

void print_arr(int *arr){
    printf("Sorted array :");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}