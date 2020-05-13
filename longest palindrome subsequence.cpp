class Solution {
public:
    int longestPalindromeSubseq(string s1) {
        vector<vector<int>> dp(s1.length()+2, vector<int>(s1.length()+2));
        string s2 = s1;
        reverse(s2.begin(),s2.end());

        for(int i=0;i<s1.length();i++)
        {
            dp[0][i] = 0;
            dp[i][0] = 0;
        }

        for(int i=1;i<=s1.length();i++)
        {
            for(int j=1;j<=s2.length();j++)
            {
                if(s1[i-1] == s2[j-1])
                    dp[i][j] = dp[i-1][j-1] + 1;
                else
                    dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};
