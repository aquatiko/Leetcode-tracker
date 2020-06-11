class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        bool dp[n][n];
        memset(dp, false, sizeof(dp));
        unordered_set<string> mp;
        for(auto str:wordDict)
            mp.insert(str);

        for(int i=n-1;i>=0;i--)
        {
            string tmp = "";
            for(int j=i;j<n;j++)
            {
                tmp+=s[j];
                if(mp.find(tmp)!=mp.end())
                {
                    dp[i][j] = true;
                    if(j+1<n)
                    dp[i][n-1] |= dp[j+1][n-1];
                }

                //cout<<dp[i][j]<<" ";
            }
            //cout<<tmp<<" "<<i;
            //cout<<endl;
        }

        return dp[0][n-1];
    }
};

// Similar to Integer Break
