// #include <bits/stdc++.h>
// using namespace std;
// string prefixToInfix(const string &s){
//     stack<string>st;
//     unordered_map<char,int>mymap;
//     mymap['+']=1;
//     mymap['-']=1;
//     mymap['*']=1;
//     mymap['/']=1;
//     for(auto it:s){
//         if(mymap[it]){
//             string a = st.top();
//             st.pop();
//             string b = st.top();
//             st.pop();

//             string temp = '('+ a + it + b +')';
//             st.push(temp);
//         }
//         else{
//             string temp(1,it);
//             st.push(temp);
//         }
//     }
//     return st.top();
// }
// int rankFunc(char ch){
//     if(ch == '^') return 3;
//     else if(ch == '*' || ch == '/') return 2;
//     else if(ch == '+' || ch == '-') return 1;
//     else return -1;
// }
// string infixToPostix(const string &s){
//     stack<char>stack;
//     string result;
//     for(int i = 0 ;i<s.size();i++){
//         char ch = s[i];
//         if((ch >='0' && ch <='9')&&(ch>='a' && ch<='z') && (ch>='A' && ch<='Z')) result+=ch;
//         else if(ch == '(') stack.push(ch);
//         else if(ch==')') {
//             while(!stack.empty()){
//                 result+=stack.top();
//                 stack.pop();
//             }
//         }
//         else{
//             if(!stack.empty() && rankFunc(ch) <=  rankFunc(stack.top())){
//                 result+=stack.top();
//                 stack.pop();
//             }
//             stack.push(ch);
//         }
//     }
//     return result;
// }
// string preToPost(string s) {
//     return prefixToInfix(infixToPostix(s)) ;
// }
string preToPost(string s) {
    // Write Your Code Here
    stack<string> st;
    string ans;
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]>='A' && s[i]<='Z'){
            st.push(string(1,s[i]));
        }else{
            string s1=st.top();
            st.pop();
            string s2=st.top();
            st.pop();
            string temp=s1+s2+s[i];
            st.push(temp);
        }
    }
    while(!st.empty()){
        ans=ans+st.top();
        st.pop();
    }
    return ans;
}



https://www.naukri.com/code360/problems/convert-prefix-to-postfix_8391014?leftPanelTabValue=PROBLEM
