class MinStack {
    stack<pair<int,int>>st;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int min;
        if(st.empty()) min = val;
        else min = std::min(st.top().second,val);
        st.push({val,min});
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top().first;    
    }
    
    int getMin() {
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */


class MinStack {
private:
    stack<int> s1;    
    stack<int> s2;   //for containing min value at top 
public:
    void push(int x) {
	    s1.push(x);
	    if(s2.empty() || x<=s2.top()) s2.push(x);	    
    }
    void pop() {
	    if(s1.top()==s2.top()) s2.pop();
	    s1.pop();
    }
    int top() {
	    return s1.top();
    }
    int getMin() {
	    return s2.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */




https://leetcode.com/problems/min-stack/description/
