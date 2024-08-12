class Solution {
    int helper(vector<int>&nums,vector<int>&dp,int n){
        if(n<0) return 0;
        if(dp[n] != -1) return dp[n];
        int take = 0;
        if(n>=2) take = nums[n] + helper(nums,dp,n-2);
        else take = nums[n];
        int skip= helper(nums,dp,n-1);

        return dp[n]=max(take,skip);
    }
public:
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return helper(nums,dp,nums.size()-1);
    }
};




class Solution
{
    public:
        LOGIC

        KARNA KYA HAIN❓
        1. Main chor hu mujhe chori karni hain.
        2. Mujhe jyada se jyada lootna hain bina police ko pata lage.
        3. Dikkat hain ki main 2 adjacent house se chori nahin kar sakta kyoki
        udhar security system laga hain.
        4. Mujhe houseAmount array is given now I want to loot as much as I can 
        without informing the police.

        APPROACH & INTUITION
        1. Ab chor ke paas 2 choice hain:-
        - Kisi ghar ki chori kare to agle ghar ko chodke aage ke gharo mein
        chori kare.
        - Ya to current ghar chod de aur aage ke gharo se chori kare.
        2. So its a type of 💡Pick/Non-Pick💡variant.
        3. So Pick/non-pick mein we will use RECURSION
        4. What do we do in RECURSION❓
        - Visualize it in the form of indexes.
        - Do all stuff on these indexes according to statement.
        - Count means SUM , minimize means min , maximize means max
        5. What is the relation here❓
        pick = f(i-2)+currentHomeAmount 
        =>current ghar liya to pichle ghar ko
        chod diya .
        notPick = f(i-1)+0 
        => current ghar ko chodke pichla ghar liya
        BASE CASE:- 
        ind <0 hua to matlab hamne chori nahin ki abhi tak -return 0
        ind 0 hua to matlab hamne pehle ghar ki chori kari abhi tak-return nums[0]
        6.Ab inme se max nikalna hain.
        7. Now there will overlapping-subproblems
        8. RECUSRSION -> MEMOIZATION -> TABULATION -> SpaceOPTIMIZATION
        9. RECUSRION to Memoization
        - Check the changing parameter(house no)
        - Declare dp array of size n
        - Store the max result as dp[i]
        - Check if dp[ind] is not looted before.
        10. Memoization to Tabulation
        - Declare the dp array size.
        - Declare the base cases.
        - Iterate till last house
        - Replace f(ind) with dp[ind]
        11. Tabulation to Space Optimization
        - Try to find do we need a dp array?
        - Try to find if there is any pattern found amond dp[i],dp[i-1],..
        - Gneralize this in terms of variables

//==============================================================================================
        
       	//Recursive Solution
           int Recursion(int i, vector<int> &nums)
       	    {
       	        if (i == 0)
       	            return nums[i];
       	        if (i < 0)
       	            return 0;
       	        int pick = nums[i] + Recursion(i - 2, nums);
       	        int nonPick = 0 + Recursion(i - 1, nums);
       	        return max(pick, nonPick);
       	    }
       	int rob(vector<int> &nums)
       	{
       	    int n = nums.size() - 1;
       	    return Recursion(n, nums);
       	}

       	//Memoization
 	        int Memoization(int i, vector<int> &nums, vector<int> &dp)
       	        {
       	            if (i == 0)
       	                return nums[0];
       	            if (i < 0)
       	                return 0;
       	            if (dp[i] != -1)
       	                return dp[i];
       	            int pick = nums[i] + Memoization(i - 2, nums, dp);
       	            int nonPick = 0 + Memoization(i - 1, nums, dp);
       	            return dp[i] = max(pick, nonPick);
       	        }
       	    int rob(vector<int> &nums)
       	    {
       	        int n = nums.size();
       	        vector<int> dp(n, -1);
       	        return Memoization(n-1, nums, dp);
       	    }

       	//Tabulation(Unoptimized)
 int rob(vector<int> &nums)
        {
            int n = nums.size();
            vector<int> dp(n, -1);
            dp[0] = nums[0];
            for (int i = 1; i < n; i++)
            {
                int pick = nums[i];
                if (i > 1)
                    pick = pick + dp[i - 2];
                int notPick = 0 + dp[i - 1];
                dp[i] = max(pick, notPick);
            }
            return dp[n - 1];
        }

   	//Tabulation(Optimized)
    int rob(vector<int> &nums)
    {
        int n = nums.size();
        int prev1 = nums[0];
        int prev = 0;
        int curri = 0;
        for (int i = 1; i < n; i++)
        {
            int pick = nums[i];
            if (i > 1)
                pick = pick + prev;
            int notPick = 0 + prev1;
            curri = max(pick, notPick);
            prev = prev1;
            prev1 = curri;
        }
        return prev1;
    }
};



https://leetcode.com/problems/house-robber/description/
