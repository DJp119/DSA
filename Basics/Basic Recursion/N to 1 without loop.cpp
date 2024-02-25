vector<int> helper(vector<int> &arr, int x) {
  if (x==0)
    return arr;
  arr.push_back(x);
  return helper(arr, x-1);
}

vector<int> printNos(int x) {
  vector<int> arr;
  return helper(arr, x);
}

https://www.codingninjas.com/studio/problems/n-to-1-without-loop_8357243?leftPanelTabValue=PROBLEM
