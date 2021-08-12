#include <stdio.h>

void selection_sort(int *);
void swap(int *, int *);
void print_arr(int *);

int main(){
    int arr[10];
    printf("Enter array of length 10: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    selection_sort(arr);
    print_arr(arr);
    return 0;
}

void selection_sort(int *arr){
    for(int i=0;i<10;i++){
        int min_index = i;
        for(int j=i;j<10;j++){
            if(arr[j]<arr[i]){
                min_index = j;
            }
        }
        swap(&arr[i],&arr[min_index]);
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