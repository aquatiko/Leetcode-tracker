static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int numSquares(int n) {
        vector<int> squares;
        squares.push_back(1);
        vector<int> dp(n+2,INT_MAX);
        dp[0] = 0;
        dp[1] = 1;

        for(int i=2;i<=n;i++)
        {
            if((int)sqrt(i)*sqrt(i) == i)
                squares.push_back(i);
            int tmp_ans = INT_MAX;

            for(int j=squares.size()-1;j>=0;j--)
                tmp_ans = min(tmp_ans, 1+dp[i-squares[j]]);
            dp[i] = tmp_ans;
        }
        return dp[n];
    }
};

// Very similar to integer Break question. Repeated pattern. Easier when thining in a bottom-up manner
