class Solution {
public:
    int findLength(vector<int>& a, vector<int>& b) {
        int dp[a.size()+1][b.size()+1];
        memset(dp,0,sizeof(dp));
        int ans = 0;
        for(int i =1;i<=a.size();i++)
        {
            for(int j=1;j<=b.size();j++)
            {
                    if(a[i-1] == b[j-1])
                    {dp[i][j] = 1+dp[i-1][j-1];
                    ans = max(ans, dp[i][j]);
                    }
            }
        }
        return ans;
    }
};

// the varation of subsequence to subarray is important to note here.
