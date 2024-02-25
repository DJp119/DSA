vector<int> rev(vector<int>&nums,int i,int j){
    if(j<i) return nums;
    swap(nums[i],nums[j]);
    i++;
    j--;
    return rev(nums,i++, j--);
}
vector<int> reverseArray(int n, vector<int> &nums)
{
    int i=0;
    int j=n-1;
    rev(nums,i,j);
    return nums;
}

https://www.codingninjas.com/studio/problems/reverse-an-array_8365444?leftPanelTabValue=PROBLEM
