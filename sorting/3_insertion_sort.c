#include <stdio.h>

void insertion_sort(int *);
void print_arr(int *);

int main(){
    int arr[10];
    printf("Enter array of length 10: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    insertion_sort(arr);
    print_arr(arr);
    return 0;
}

void insertion_sort(int *arr){
    int key;
    for(int i=0;i<10;i++){
        int j=i-1;
        key = arr[i];
        while(j>=0 && key<arr[j]){
            arr[j+1] = arr[j];
            j -= 1;

        }
        arr[j+1] = key;
    }
}

void print_arr(int *arr){
    printf("Sorted array :");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}