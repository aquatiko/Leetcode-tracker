class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size()+3,vector<int> (nums.size()+3, -1));

        return solve(nums,dp, nums.size()-1, nums.size());
    }

    int solve(vector<int> &nums, vector<vector<int>> &dp, int pos, int prev)
    {
        if(pos <0)
            return 0;

        if(dp[pos][prev]!=-1)
            return dp[pos][prev];

        if(prev == nums.size())
            return dp[pos][prev] = max(1+ solve(nums, dp, pos-1, pos), solve(nums, dp, pos-1, prev));
        else
            return dp[pos][prev] = max(nums[pos]>=nums[prev] ? 0: 1+ solve(nums, dp, pos-1, pos), solve(nums, dp, pos-1, prev));
    }
};

// This is a O(n^2) solution in time ans space. See other optimized versions.
