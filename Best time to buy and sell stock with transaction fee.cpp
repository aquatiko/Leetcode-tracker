static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {

        if(prices.size()<2)
            return 0;
        int has0_buy = -prices[0] - fee, has0_doNothing = 0, has1_sell = 0, has1_doNothing = -prices[0] - fee;

        for(int i=0;i<prices.size();i++)
        {
            int new_has0_buy = max(has1_sell, has0_doNothing) - prices[i] - fee;
            int new_has0_doNothing = max(has1_sell, has0_doNothing);
            int new_has1_sell = max(has1_doNothing, has0_buy) + prices[i];
            int new_has1_doNothing = max(has1_doNothing, has0_buy);

            has0_buy = new_has0_buy;
            has0_doNothing = new_has0_doNothing;
            has1_sell = new_has1_sell;
            has1_doNothing = new_has1_doNothing;
        }

        return max(max(has0_buy, has0_doNothing), max(has1_sell, has1_doNothing));
    }
};

// Similar to .. with cooldown problem just modified 2-3 lines.
