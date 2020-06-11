class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int has0_buy = -prices[0], has0_doNothing = 0, has1_sell = 0, has1_doNothing = -prices[0];

        for(int i=0;i<prices.size();i++)
        {
            int new_has0_buy = has0_doNothing - prices[i];
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

// a very strong general logic is behind this Solution. That genralizes the questions o this type.
// Choices + their realtions => reccurance relations (basis of this question)
