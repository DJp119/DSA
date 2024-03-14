pair<int, int> getFloorAndCeil(vector<int> &a, int n, int x) {
	pair<int,int>ans;
	ans.first = -1;
	ans.second =-1;
	int low = 0 , high = a.size()-1;
	while(low<=high){
		int mid = high + (low-high)/2;
		if(a[mid]==x){
			ans.first = x;
			ans.second = x;
			return ans;
		}
		else if(a[mid]>x){
			ans.second=a[mid];
			high = mid-1;
		}
		else{
			ans.first = a[mid];
			low = mid+1;
		}
	}
	return ans;	
}

https://www.codingninjas.com/studio/problems/ceiling-in-a-sorted-array_1825401?leftPanelTabValue=PROBLEM
