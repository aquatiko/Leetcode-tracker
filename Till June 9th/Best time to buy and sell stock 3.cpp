static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices) {
         if(prices.size()<2)
            return 0;
        int k =2;
        vector<vector<int>> dp(2, vector<int>(prices.size()+1,0));
        int flag = 0;
        for(int trans=1;trans<=k;trans++)
        {   int mem = -prices[0];

            for(int day=1;day<prices.size();day++)
            {
                mem = max(mem, dp[flag%2][day-1] - prices[day-1]);
                int no_selection = dp[(flag+1)%2][day-1];
                int selection = prices[day] + mem;
                dp[(flag+1)%2][day] = max(selection, no_selection);
            }
         flag = (flag+1)%2;
        }
        return dp[flag][prices.size()-1];
    }
};
