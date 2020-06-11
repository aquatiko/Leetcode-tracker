static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& arr) {
        vector<vector<int>> dp(102, vector<int> (102, -1));

        int ans = INT_MAX;
        for(int i=0;i<arr.size();i++)
            ans = min(ans, solve(dp, arr, 0, i));

        return ans;
    }

    int solve(vector<vector<int>> &dp, vector<vector<int>> &arr, int row, int pos)
    {

        if(pos<0 || pos>= arr[0].size())
            return INT_MAX;
        if(row == arr.size()-1)
            return arr[row][pos];

        if(dp[row][pos]!=-1)
            return dp[row][pos];

        int leftNext = solve(dp, arr, row+1, pos-1);
        int rightNext = solve(dp, arr, row+1, pos+1);
        int below = solve(dp, arr, row+1, pos);

        return dp[row][pos] = arr[row][pos] + min(below, min(leftNext, rightNext));
    }
};
