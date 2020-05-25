
class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        vector<vector<int>> dp(arr.size()+2, vector<int>(arr.size()+2,-1));
        return solve(arr,dp, diff,arr.size()-1,arr.size());
    }
    int solve(vector<int>& arr,vector<vector<int>> &dp, int diff, int pos, int last)
    {
        if(pos<0)
            return 0;
        if(dp[pos][last]!=-1)
            return dp[pos][last];

        int choice1 = solve(arr,dp, diff, pos-1, last);
        int choice2 = last == arr.size() || arr[last]-arr[pos]==diff ? 1+solve(arr,dp, diff, pos-1, pos) : 0;
        return dp[pos][last] = max(choice1, choice2);
    }
};
