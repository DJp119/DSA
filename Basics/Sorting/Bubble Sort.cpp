void bubbleSort(vector<int>& arr, int n) 
{
    for(int i = n-1;i>=1;i--){
        for(int j=0;j<i;j++){
            if(arr[j]>arr[j+1]) swap(arr[j],arr[j+1]);
        }
    }
}

https://www.codingninjas.com/studio/problems/bubble-sort_624380?leftPanelTabValue=PROBLEM
