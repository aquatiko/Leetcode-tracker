class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int target = 0;
        for(auto num:nums)
            target+=num;
        if(target%2!=0)
            return false;
        target/=2;

        bool dp[target+1];
        memset(dp,false,sizeof(dp));

        dp[0] = true;

        for(int i=0;i<nums.size();i++)
        {
            for(int j=target;j>=nums[i];j--)
            {
                dp[j] = dp[j] | dp[j-nums[i]];
            }
        }
        return dp[target];
    }
};

// Time of O(n^2) can't be opimized further but
// Space complexity can be optimized from O(n^2) to O(2n) to O(n).
// O(2n) to O(n) really becomes possible when the implementation is done in a certain way.
// Note the implementation which is done here and how smartly we reduced the space complexity. Can be extended to other problems
