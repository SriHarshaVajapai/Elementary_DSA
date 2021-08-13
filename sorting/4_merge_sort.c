#include <stdio.h>

void merge_sort(int *, int, int);
void merge(int *, int, int, int);
void print_arr(int *);

int main(){
    int arr[10];
    printf("Enter array of length 10: ");
    for(int i=0;i<10;i++){
        scanf("%d",&arr[i]);
    }
    merge_sort(arr,0,9);
    print_arr(arr);
    return 0;
}

void merge(int *arr,int start, int mid, int end){
    int i=start,j=mid+1,k=start;
    int merged_arr[end+1];
    while(i<=mid && j<=end){
        if(arr[i]<arr[j]) merged_arr[k++] = arr[i++];
        else merged_arr[k++] = arr[j++];
    }
    while(i<=mid) merged_arr[k++] = arr[i++];
    while(j<=end) merged_arr[k++] = arr[j++];
    for(int i=start;i<=end;i++){
        arr[i] = merged_arr[i];
    }
}

void merge_sort(int *arr,int start, int end){
    if(start>=end) return;
    else{
        int mid = start+(end-start)/2;
        merge_sort(arr,start,mid);
        merge_sort(arr,mid+1,end);
        merge(arr,start,mid,end);
    }
}

void print_arr(int *arr){
    printf("Sorted array :");
    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}