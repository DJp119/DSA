class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int leftsum = 0 , rightsum =0 , maxsum = 0;
            for(int i=0;i<k;i++){
                leftsum+=cardPoints[i];
            }
            maxsum = leftsum;
            int rightindex = cardPoints.size()-1;
            for(int leftindex =k-1;leftindex>=0;leftindex--){
                leftsum-=cardPoints[leftindex];
                rightsum += cardPoints[rightindex];
                rightindex--;
                maxsum = max(maxsum,leftsum+rightsum);
            }
    return maxsum;
    }

};



TC - O(N)
SC - O(1)

https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/
