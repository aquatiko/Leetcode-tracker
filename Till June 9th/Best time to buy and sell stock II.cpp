class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()<2)
            return 0;
        int ans = 0;
        for(unsigned short int i=0;i<prices.size()-1;++i)
            ans += max(0, prices[i+1]-prices[i]);

        return ans;
    }
};

// There are two approaches to this question . The one written here is very smart intution behind it.
