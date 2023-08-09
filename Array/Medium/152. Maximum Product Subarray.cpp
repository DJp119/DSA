class Solution {
public:
    int maxProduct(vector<int>& nums) {
    
    if(nums.empty()) {
        return 0;
    }
    
    int currentMax = nums[0];
    int currentMin = nums[0];
    int maxProduct = nums[0];
    
    for(int i = 1; i < nums.size(); ++i) {
        //calculate our new possibilities for this round
        
        int p1 = currentMax * nums[i];
        int p2 = currentMin * nums[i];

        //our currentMax will be either p1 or p2 or nums[i] whichever is bigger
        
        currentMax = max(nums[i], max(p1, p2));
        //our currentMin will be either p1 or p2 or nums[i] whichever is smaller
        
        currentMin = min(nums[i], min(p1, p2));
        //our maxProduct will be our currentMax or our maxProduct, whichever is bigger.
        
        maxProduct = currentMax > maxProduct ? currentMax : maxProduct;
    }
    return maxProduct;
}
};
