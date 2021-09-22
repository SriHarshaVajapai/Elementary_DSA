#include <stdio.h>

void quick_sort(int *arr, int start, int end);
int partition(int *arr, int start, int end);
void swap(int *a, int *b);

int main(){
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++) scanf("%d",&arr[i]);
    quick_sort(arr,0,n-1);
    for(int i=0;i<n;i++) printf("%d ",arr[i]);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

    int partition(int *arr, int start, int end)
{
    int i=start-1,pivot=arr[end];
    for(int j=start;j<=end-1;j++){
        if(arr[j]<pivot){
            i=i+1;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[end]);
    return i+1;
}

void quick_sort(int *arr, int start, int end){
    if(start<end){
        int pivot = partition(arr,start,end);
        quick_sort(arr,start,pivot-1);
        quick_sort(arr,pivot+1,end);
    }
}