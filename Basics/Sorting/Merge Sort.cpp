void merge(int arr[],int l,int mid,int r){
    int *temp = new int[r - l + 1];
    int left=l;
    int right=mid+1;
    int k=0;
    while(left<=mid && right<=r){
        if(arr[left]<=arr[right]){
            temp[k++]=(arr[left]);
            left++;
        }
        else{
            temp[k++]=arr[right];
            right++;
        }
    }
    while(left<=mid){
        temp[k++]=arr[left];
        left++;
    }
    while(right<=r){
        temp[k++]=arr[right];
        right++;
    }
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
}
void mergeSort(int arr[], int l, int r) {
    if(l>=r) return;
    int mid=(l+r)/2;
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
    merge(arr,l,mid,r);
}

https://www.codingninjas.com/studio/problems/merge-sort_5846?leftPanelTabValue=PROBLEM
