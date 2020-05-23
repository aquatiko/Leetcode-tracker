class Solution {
public:
    int dp[21][2002];
    int findTargetSumWays(vector<int>& nums, int s) {
        memset(dp,-1,sizeof(dp));
        return solve(nums, s, nums.size()-1, 0);
    }
    int solve(vector<int> &nums, int s, int pos, int sum)
    {
        if(pos<0 && sum == s)
            return 1;
        if(pos<0 && sum != s)
            return 0;
        if(dp[pos][sum+1000]!=-1)
            return dp[pos][sum+1000];
        return dp[pos][sum+1000] = solve(nums, s, pos-1, sum+nums[pos]) + solve(nums, s, pos-1, sum-nums[pos]);
    }
};

// This is a 2D dp solution. Very easy to come up with.
// 1D D.P solution can be written easily with botttom up table filling approach where we realize that we only need two rows at
// a time, so we can reduce the space complexity.
