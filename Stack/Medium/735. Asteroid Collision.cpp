class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>mystack;
        for(int i=0;i<asteroids.size();i++){
            if(asteroids[i]>0 || mystack.empty()) mystack.push(asteroids[i]);
            else{
                while(!mystack.empty() && mystack.top() > 0 && (mystack.top() <abs(asteroids[i]))){
                    mystack.pop();
                } 
                if(!mystack.empty() && mystack.top()==abs(asteroids[i])) mystack.pop();
                else {
                    if(mystack.empty() || mystack.top()<0) mystack.push(asteroids[i]);
                }
            }
        }
        vector<int>ans;
        while(!mystack.empty()){
            ans.push_back(mystack.top());
            mystack.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};


https://leetcode.com/problems/asteroid-collision/



class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        std::stack<int> stack;
        for (int a : asteroids) {
            if (a > 0) {
                stack.push(a);
            } else {
                while (!stack.empty() && stack.top() > 0 && stack.top() < -a) {
                    stack.pop();
                }
                if (stack.empty() || stack.top() < 0) {
                    stack.push(a);
                }
                if (!stack.empty() && stack.top() == -a) {
                    stack.pop();
                }
            }
        }
        std::vector<int> res(stack.size());
        int i = stack.size() - 1;
        while (!stack.empty()) {
            res[i--] = stack.top();
            stack.pop();
        }
        return res;        
    }
};
