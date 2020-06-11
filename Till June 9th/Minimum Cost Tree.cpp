static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        vector<vector<int>> dp(42, vector<int>(42, -1));

        return solve(dp,arr, 0, arr.size()-1);
    }

    int solve(vector<vector<int>> &dp, vector<int> &arr, int start, int end)
    {
        if(start>end)
            return 0;

        if(start == end)
        {
            return 0;
        }

        if(end - start == 1)
        {
            dp[start][end] = arr[start]*arr[end];
            return dp[start][end];
        }

        if(dp[start][end]!=-1)
            return dp[start][end];

        int tmp_ans = INT_MAX;
        for(int k=start;k<end;k++)
        {
            tmp_ans = min(tmp_ans, solve(dp,arr, start, k) + solve(dp,arr, k+1, end) + maxRange(arr, start,k)*maxRange(arr, k+1, end));
        }

        return dp[start][end] = tmp_ans;
    }

    int maxRange(vector<int> &arr, int start, int end)
    {
        int maxEle = arr[start];
        for(int i=start+1;i<=end;i++)
            if(arr[i]>maxEle)
                maxEle = arr[i];
        return maxEle;
    }
};
