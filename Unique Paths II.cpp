class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        if(arr.size()==0)
            return 0;
        if(arr.size()==1 && arr[0].size()==1)
            return (arr[0][0]+1)%2;
        vector<vector<int>> dp(arr.size(), vector<int> (arr[0].size(),-1));
        return solve(arr,dp, arr.size()-1, arr[0].size()-1);
    }
    int solve(vector<vector<int>> &arr, vector<vector<int>> &dp, int x, int y)
    {
        if(x == 0 && y == 0)
            return 1;
        if(x<0 || y<0)
            return 0;

        if(dp[x][y]!=-1)
            return dp[x][y];
        if(arr[x][y] == 1)
            return 0;

        int choice1 = x-1>=0 && arr[x-1][y]!=1 ? solve(arr,dp, x-1, y) : 0;
        int choice2 = y-1>=0 && arr[x][y-1]!=1 ? solve(arr,dp, x,y-1) : 0 ;

        return dp[x][y] = choice1 + choice2;
    }
};
