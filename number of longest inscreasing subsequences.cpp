class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        vector<int> count(nums.size(),1);

        int best = 1;
        for(int i=1;i<nums.size();i++)
        {
            int maxi = 0, cnt=0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i] && dp[j]>maxi)
                {maxi = dp[j]; cnt=count[j];}
                else if(nums[j]<nums[i] && dp[j]==maxi)
                    cnt += count[j];
            }
            dp[i] = maxi+1;
            count[i] = max(cnt,1);

            best = max(best, dp[i]);
        }
        int ans = 0;

        for(int i = 0;i<nums.size();i++)
        {
            if(dp[i] == best)
                ans+=count[i];
            //cout<<dp[i]<<" "<<count[i]<<"\t";
        }
        return ans;
    }
};
