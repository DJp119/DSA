/*
    Time Complexity: O(n)
    Space Complexity: O(n)

    Where n is the length of the input string.
*/

#include <bits/stdc++.h>
string postfixToPrefix(string &s){
    stack<string>mystack;
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]>='a' && s[i] <='z'){
            string temp(1,s[i]);
            mystack.push(temp);
        }
        else{
            string a = mystack.top();
            mystack.pop();
            string b = mystack.top();
            mystack.pop();
            string temp =s[i]+  b + a;
            mystack.push(temp); 
        }
    }
    while(!mystack.empty()){
        ans+=mystack.top();
        mystack.pop();
    }
    return ans;
}
