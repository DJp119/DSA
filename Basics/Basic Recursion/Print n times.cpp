vector<string> rec(vector<string>&ans,int a){
	if(a==0) return ans;
	ans.push_back("Coding Ninjas");
	return rec(ans,a-1);
}

vector<string> printNTimes(int n) {
	vector<string>ans;
	rec(ans,n);
	return ans;
}
https://www.codingninjas.com/studio/problems/-print-n-times_8380707?leftPanelTabValue=PROBLEM
