class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        if(nums.size()==1)
            return nums[0];
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size(),-1));
        return max(solve(nums,dp, 0, nums.size()-2), solve(nums, dp, 1, nums.size()-1));
    }
    int solve(vector<int> &nums,vector<vector<int>> &dp, int l, int r)
    {
        if(l==r)
            return nums[l];
        if(l>r)
            return 0;

        if(dp[l][r]!=-1)
            return dp[l][r];

        return dp[l][r] = max(nums[l] + solve(nums,dp, l+2, r), solve(nums,dp, l+1, r));
    }
};
