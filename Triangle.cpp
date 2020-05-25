static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int minimumTotal(vector<vector<int>>& arr) {
        int dp[arr.size()+1];
        dp[0]=0;
        for(int i=0;i<arr[arr.size()-1].size();i++)
            dp[i]=arr[arr.size()-1][i];

        for(int i=arr.size()-2;i>=0;i--)
        {
            for(int j=0;j<=i;j++)
                dp[j] = arr[i][j] + min(dp[j], dp[j+1]);
        }
        return dp[0];
    }
};
