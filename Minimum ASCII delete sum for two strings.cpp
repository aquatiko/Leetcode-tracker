static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int dp[1002][1002];
    int minimumDeleteSum(string s1, string s2)
    {
        dp[0][0] = 0;

        for(int i=0;s1[i]!=NULL;i++)
            dp[i+1][0] = dp[i][0]+s1[i];

        for(int i=0;s2[i]!=NULL;i++)
            dp[0][i+1] = dp[0][i]+s2[i];

        for(int i=0;s1[i]!=NULL;i++)
        {
            for(int j=0;s2[j]!=NULL;j++)
            {
                if(s1[i] == s2[j])
                    dp[i+1][j+1] = dp[i][j];
                else
                    dp[i+1][j+1] = min(s1[i]+dp[i][j+1], s2[j]+dp[i+1][j]);
            }
        }

        return dp[s1.length()][s2.length()];
    }

};

// Smallest subsequence type dp
