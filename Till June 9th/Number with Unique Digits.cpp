class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n>10)
            return 0;
        if(n==0)
            return 0;
        if(n==1)
            return 10;
        int dp[11];
        dp[0] = 1;
        dp[1] = 9;
        int res = 10;
        for(int i=2;i<=n;i++)
        {
            dp[i] = dp[i-1]*(10 - (i-1));
            res += dp[i];
        }
        return res;
    }
};
