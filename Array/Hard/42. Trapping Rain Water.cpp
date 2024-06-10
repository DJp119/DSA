TC - O(N)
SC - O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_height(n);  // Initialize with size 'n'
        vector<int> right_height(n); // Initialize with size 'n'

        // Calculate the maximum height from the left
        int maxi = INT_MIN;
        for (int i = 0; i < n; i++) {
            maxi = max(height[i], maxi);
            left_height[i] = maxi;
        }

        // Calculate the maximum height from the right
        maxi = INT_MIN; // Reset 'maxi'
        for (int i = n - 1; i >= 0; i--) {
            maxi = max(height[i], maxi);
            right_height[i] = maxi;
        }

        // Calculate trapped water
        int water = 0;
        for (int i = 0; i < n; i++) {
            water += min(left_height[i], right_height[i]) - height[i];
        }

        return water;
    }
};

TC - O(N)
SC - O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = height.size()-1;
        int maxLeft = height[left];
        int maxRight =height[right];
        int ans = 0;
        while(left<right){
            if(maxLeft<=maxRight){
                left++;
                maxLeft = max(maxLeft,height[left]);
                ans += (maxLeft-height[left]);
            }
            else{
                right--;
                maxRight = max(maxRight,height[right]);
                ans += (maxRight-height[right]);
            }
        }
        return ans;
    }
};

