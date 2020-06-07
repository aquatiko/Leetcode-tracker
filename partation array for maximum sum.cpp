class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& a, int k) {
        int n = a.size();
        vector<int> dp(n+1);
        dp[0] = 0;

        for(int i=1;i<=n;i++)
        {   int tmp_ans = a[i-1]+dp[i-1];
            int maxi = a[i-1];
            for(int j = 2;j<=k && i-j>=0;j++)
            {
                if(maxi<a[i-j])
                    maxi = a[i-j];
                tmp_ans = max(tmp_ans, maxi*j + dp[i-j]);
            }
            dp[i] = tmp_ans;
            //cout<<dp[i]<<" ";
        }
        return dp[n];
    }
};
