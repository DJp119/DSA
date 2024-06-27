#include <bits/stdc++.h>
void ordered(stack<int>&stack,int num){
	if((stack.empty() )|| ( !stack.empty() && stack.top()<num) ) {

	stack.push(num);
	return;
	} 

	int k = stack.top();
	stack.pop();

	ordered(stack, num);
	stack.push(k);
	
} 
void sortStack(stack<int> &stack)
{
	if(stack.empty()) return;
	int num = stack.top();
	stack.pop();
	sortStack(stack);
	ordered(stack,num);
	// stack.push(num);
}


https://www.naukri.com/code360/problems/sort-a-stack_985275
