// TOp Down Approach

class Solution {
public:
    int dp[601][101][101];
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> arr;
        for(int i=0;i<strs.size();i++)
        {
            int zeros = 0;
            int ones = 0;
            for(int j=0;j<strs[i].length();j++)
                if(strs[i][j]=='1')
                    ones++;
                else
                    zeros++;
            arr.push_back({zeros,ones});
        }
        memset(dp,-1,sizeof(dp));
        return solve(arr, m, n, arr.size()-1);
    }
    int solve(vector<pair<int,int>> &arr,int m,int n, int pos)
    {
        if(pos<0)
            return 0;
        if(dp[pos][m][n]!=-1)
            return dp[pos][m][n];

        int choice1 = solve(arr, m, n, pos-1);
        int choice2 = arr[pos].first>m || arr[pos].second>n ? 0 : 1+solve(arr,m-arr[pos].first, n-arr[pos].second, pos-1);
        return dp[pos][m][n] = max(choice1, choice2);

    }
};

// Bottom-up code more optimized

class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>> arr;
        for(int i=0;i<strs.size();i++)
        {
            int zeros = 0;
            int ones = 0;
            for(int j=0;j<strs[i].length();j++)
                if(strs[i][j]=='1')
                    ones++;
                else
                    zeros++;
            arr.push_back({zeros,ones});
        }
        int dp[m+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<arr.size();i++)
        {
            for(int j=m;j>=arr[i].first;j--)
            {
                for(int k=n;k>=arr[i].second;k--)
                {dp[j][k] = max(dp[j][k], 1+dp[j-arr[i].first][k-arr[i].second]);}
            }
        }
        return dp[m][n];
    }

};
