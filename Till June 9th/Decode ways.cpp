class Solution {
public:
    int numDecodings(string s) {
        if(s.length()==0)
            return 0;
        vector<int> dp(s.length(),-1);
        return solve(s,dp, 0);
    }
    int solve(string s,vector<int> &dp, int pos)
    {
        if(pos==s.length())
            return 1;
        if(s[pos]=='0')
            return 0;
        if(dp[pos]!=-1)
            return dp[pos];
        int choice1 = solve(s,dp,pos+1);
        int choice2 = 0;
        if(pos+1<s.length() && stoi(s.substr(pos,2))<=26)
            choice2 = solve(s,dp,pos+2);
        //cout<<pos<<" "<<choice1<<" "<<choice2<<"\t";
        return dp[pos] = choice1+choice2;
    }
};
