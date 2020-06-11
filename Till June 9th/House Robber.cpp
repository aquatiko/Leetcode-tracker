class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0)
            return 0;

        if(nums.size() == 1)
            return nums[0];

        if(nums.size() == 2)
            return max(nums[0], nums[1]);

        vector<int> dp(nums.size()+2, -1);

        solve(nums, dp, nums.size()-1);
        solve(nums, dp, nums.size()-2);

        return max(dp[nums.size()-1], dp[nums.size()-2]);
    }

    int solve(vector<int> &nums, vector<int> &dp, int pos)
    {
        if(pos<0)
            return 0;

        if(dp[pos] !=-1)
            return dp[pos];

        return dp[pos] = max(solve(nums,dp, pos-2), solve(nums,dp, pos-3)) + nums[pos];
    }
};
