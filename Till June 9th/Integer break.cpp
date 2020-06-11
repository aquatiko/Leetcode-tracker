class Solution {
public:
    bool flag;
    int integerBreak(int n) {
        flag = false;
        vector<int> dp(n+1, -1);
        return solve(n,dp);
    }
    int solve(int n, vector<int> &dp)
    {   if(n<=0)
            return 0;
        if(n==1)
            return 1;
        if(dp[n]!=-1)
            return dp[n];
        int tmp_ans = flag? n:1;
        flag = true;
        for(int i=1;i<=n/2;i++)
            tmp_ans = max(tmp_ans, solve(n-i,dp)*solve(i,dp));
        return dp[n]=tmp_ans;
    }
};

// Bottom up
class Solution {
public:
    int integerBreak(int n) {
        if(n==2)
            return 1;
        if(n==3)
            return 2;
        vector<int> dp(n+1,0);
        dp[0] = 0;
        dp[1] = 1;
        for(int i=2;i<=n;i++)
        {   dp[i]=i;
            for(int j=1;j<=i;j++)
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
        }
        return dp[n];
    }
};
