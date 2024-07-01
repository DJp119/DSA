// class StockSpanner {
// public:
//     stack<pair<int,int>>st;
//     StockSpanner() {
        
//     }
    
//     int next(int price) {
//         if(st.empty()) {
//             st.push({price,1});
//             return 1;
//         } 
//         else if(st.top().first >= price) {
//             st.push({price,1}) ; return 1;

//         }
//         else {
//             int temp  =  0;
//             while(st.top().first <= price){
//                 temp+= st.top().second;
//                 st.pop();
//             }
//             cout<<"Temp"<<temp;
//             st.push({price,temp+1});
//             return temp+1;
//         }
//         // return 1;
//     }
// };

// /**
//  * Your StockSpanner object will be instantiated and called as such:
//  * StockSpanner* obj = new StockSpanner();
//  * int param_1 = obj->next(price);
//  */
class StockSpanner {
public:
    stack<pair<int, int>> st;

    StockSpanner() {
    }

    int next(int price) {
        int cnt = 1; // Initialize span for the current price

        while (!st.empty() && st.top().first <= price) {
            cnt += st.top().second; // Add the span of the top element
            st.pop();
        }

        st.push({price, cnt}); // Push the new price and its span
        return cnt;
    }
};
https://leetcode.com/problems/online-stock-span/
