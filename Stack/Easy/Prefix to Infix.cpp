#include<bits/stdc++.h>
using namespace std;
string prefixToInfixConversion(string &s){
	stack<string>st;
	string result;
	unordered_map<char,int>mymap;
	mymap['+']=1;
	mymap['-']=1;
	mymap['*']=1;
	mymap['/']=1;
	// mymap['/']=1;
	reverse(s.begin(), s.end());
	for(auto it:s){
		if(mymap[it]){
			string a = st.top();
			st.pop();
			string b = st.top();
			st.pop();
			
			string temp = '('+a+it+b+')';
			st.push(temp);
		}
		else{
			string temp(1,it);
			st.push(temp);
		}
	}
	return st.top();
}




/*
    Time Complexity: O(|s|^2)
    Space Complexity: O(|s|)

    Where '|s|' is the length of the given string.
*/

string prefixToInfixConversion(string &s)
{
    // Stack for storing the operands.
	stack<string> operands;
	int n = s.size();

	// Iterating from right to left
	for (int i = n - 1; i >= 0; i--)
	{
		// Check if the current character is a operator
		if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/')
		{
			// Taking last two operands from the stack
			string operand1 = operands.top();
			operands.pop();
			string operand2 = operands.top();
			operands.pop();

			// Combining the two operands with the current operator
			// and pushing back to the stack
			string resultantOfTwo = "(" + operand1 + s[i] + operand2 + ")";
			operands.push(resultantOfTwo);

		}
		else

		{
			// Converting the character str[i] into string
			// and pushing it into the stack
			string strTemp(1, s[i]);
			operands.push(strTemp);
		}
	}

	// Last operand in the stack will be the final answer
	return operands.top();
}



/*
    Time Complexity: O(|s|^2)
    Space Complexity: O(|s|)

    Where '|s|' is the length of the given string.
*/



https://www.naukri.com/code360/problems/prefix-to-infix_1215000?leftPanelTabValue=PROBLEM
