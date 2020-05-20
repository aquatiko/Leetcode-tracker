class Solution {
public:
    int numTrees(int n) {
        int dp[n+1];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=n;i++)
        {
            int tmp_ans = 0;
            for(int j=1;j<=i;j++)
                tmp_ans+=dp[j-1]*dp[i-j];
            dp[i]=tmp_ans;
        }
        return dp[n];
    }
};

// Very imp question with MCM based logic.
