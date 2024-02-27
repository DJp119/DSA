void selectionSort(vector<int>&arr) {
    for(int i=0;i<=arr.size()-1;i++){
        int mini = i;
        for(int j=i;j<=arr.size()-1;j++){
            if(arr[j]<arr[mini]) mini = j;
        }
        swap(arr[i],arr[mini]);
    }
}
https://www.codingninjas.com/studio/problems/selection-sort_624469?leftPanelTabValue=PROBLEM
