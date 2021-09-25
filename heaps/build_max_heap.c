#include <stdio.h>

int heap_size;

void build_max_heap(int *arr);
void max_heapify(int *arr, int i);
void swap(int *, int *);

int main(){
    int n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    heap_size=n+1;
    int arr[heap_size];
    printf("Enter the elements:\n");
    for(int i=1;i<heap_size;i++) scanf("%d",&arr[i]);
    build_max_heap(arr);
    printf("The array after the building heap:\n");
    for(int i=1;i<heap_size;i++) printf("%d ",arr[i]);
    return 0;
}

void build_max_heap(int *arr){
    for(int i=heap_size/2;i>=1;i--) max_heapify(arr,i);
}

void max_heapify(int *arr, int i){
    int left_child=2*i;
    int right_child=2*i+1;
    int largest;

    if(left_child<heap_size && arr[left_child]>arr[i])
        largest=left_child;
    else 
        largest=i;
    
    if(right_child<heap_size && arr[right_child]>arr[largest])
        largest=right_child;
    
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        max_heapify(arr,largest);
    }
}

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}