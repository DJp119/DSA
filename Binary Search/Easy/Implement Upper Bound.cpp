int upperBound(vector<int> &arr, int x, int n){
	int low = 0,high = n-1;
	int ans = n;
	while(low<=high){
		int mid = high + (low-high)/2;
		if(arr[mid]>x) ans = mid,high = mid-1;
		else low = mid+1;
	}
	return  ans;
}

  https://www.codingninjas.com/studio/problems/implement-upper-bound_8165383?leftPanelTabValue=PROBLEM
