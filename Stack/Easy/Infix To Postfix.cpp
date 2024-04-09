#include <bits/stdc++.h>
int rankFunc(char c){
	if(c == '^' ) return 3;
	else if(c=='/' || c=='*') return 2;
	else if(c == '+' || c=='-') return 1;
	else return -1;
}
string infixToPostfix(string exp){
	stack<char>s;
	string result;
	for(int i=0;i<exp.size();i++){
		char ch = exp[i];
		if((ch >= '0' && ch <= '9')||(ch >='a' && ch<='z')||(ch>='A'&&ch<='Z')) result+=ch;

		else if(ch == '(') s.push(ch);
		else if(ch==')'){
			while(s.top() != '('){
				result+=s.top();
				s.pop();
			}
			s.pop();
		}

		else{
			if(!s.empty() && (rankFunc(ch) <= rankFunc(s.top())) ){
				result+=s.top();
				s.pop();
			}
			// here else will not come beacuse while checking for the operator , we need to insert that in of the current iteration , we are missing that if we put else 
			
			 s.push(ch);
		}
	}	

	while(!s.empty()){
		result+=s.top();
		s.pop();
	}
	return result;
}



https://www.naukri.com/code360/problems/day-23-:-infix-to-postfix-_1382146?leftPanelTabValue=PROBLEM
