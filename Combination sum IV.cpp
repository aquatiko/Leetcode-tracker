class Solution {
public:
    unordered_map<int,int> dp;
    int combinationSum4(vector<int>& nums, int target) {
        return solve(nums,target);
    }
    int solve(vector<int> &nums, int target)
    {
        if(target == 0)
            return 1;
        if(target<0)
            return 0;

        if(dp.find(target)!=dp.end())
            return dp[target];
        int res = 0;
        for(int i=0;i<nums.size();++i)
        {
            res += solve(nums, target-nums[i]);
        }
        return dp[target] = res;
    }
};
