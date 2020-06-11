class Solution {
public:
    int lenLongestFibSubseq(vector<int>& arr) {
        unordered_map<int,int> mp;

        vector<vector<int>> dp(arr.size(), vector<int>(arr.size(),2));
        int ans = 2;
        for(int i=arr.size()-1;i>=0;i--)
        {   mp[arr[i]] = i;
            for(int j = i+1;j<arr.size();j++)
            {
                if(mp.find(arr[i]+arr[j])!=mp.end())
                dp[i][j] = 1 + dp[j][mp[arr[i]+arr[j]]];
                ans = max(ans, dp[i][j]);
                //cout<<dp[i][j]<<" ";
            }
            //cout<<endl;
        }
        if(ans!=2)
        return ans;
        else
        return 0;
    }
};

// Approaching this question as I would a standard D.P with tabulaiton method made the thinking easier.
