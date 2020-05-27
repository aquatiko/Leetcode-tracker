class Solution {
public:
      unordered_set<string> mp;
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        int n = s.length();
        vector<vector<bool>> dp(n, vector<bool>(n,false));
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
                    dp[i][n-1] = dp[i][n-1] | dp[j+1][n-1];
                }
            }
        }
        if(dp[0][n-1]==false)
            return {};

        return generate_sent(s,dp,0);
    }
    vector<string> generate_sent(string s, vector<vector<bool>> &dp, int pos)
    {
        if(pos>=s.length())
            return {};
        string tmp = "";
        vector<string> ans;

        for(int i=pos;i<s.length()-1;i++)
        {
            tmp+=s[i];
            if(dp[pos][i]==1)
            {
                vector<string> sub_res = generate_sent(s,dp,i+1);
                for(auto itr:sub_res)
                {
                    ans.push_back(tmp + " " + itr);
                }
            }
        }
        tmp+=s[s.length()-1];
        if(mp.find(tmp)!=mp.end())
            ans.push_back(tmp);
        return ans;
    }
};

// Extended the code of Word Break I
