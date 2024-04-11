/*
    Time Complexity: O(n^2)
    Space Complexity: O(n)
    where n is the length of the postfix expression.
*/


string postToInfix(string postfix) {
    stack<string>mystack;
    string ans;
    for(int i =0;i<postfix.size();i++){
        // if((postfix[i]>='A' && postfix[i]<='Z') || (postfix[i]>='a' && postfix[i]<='z') ) {
        if((postfix[i]>='a' && postfix[i]<='z') || (postfix[i]>='A' && postfix[i]<='Z')){
            string temp(1,postfix[i]);
            mystack.push(temp);
        }
        else{
            string a = mystack.top();
            mystack.pop();
            string b = mystack.top();
            mystack.pop();

            string temp= '(' + b +postfix[i] +a+ ')';
            mystack.push(temp);
        }
    }
    while(!mystack.empty()){
        ans+=mystack.top();
        mystack.pop();
    }
    return ans;
}

https://www.naukri.com/code360/problems/postfix-to-infix_8382386?leftPanelTabValue=PROBLEM
