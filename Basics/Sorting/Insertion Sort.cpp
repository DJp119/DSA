void swapElement(int arr[],int start,int end){
    if(end>start){
        if(arr[end-1]>arr[end]){
            int temp = arr[end];
            arr[end]=arr[end-1];
            arr[end-1]=temp;
        }
        swapElement(arr, start, end-1);
    }
}
void insertion(int arr[],int start,int end,int n){
    if(end<n){
        swapElement(arr,start,end);
        insertion(arr,start,end+1,n);
    }
}
void insertionSort(int arr[], int n)
{
    int end = 1;
    int start = 0;
    insertion(arr,start,end,n);
}

https://www.codingninjas.com/studio/problems/insertion-sort_624381?leftPanelTabValue=PROBLEM
