class Solution {
public:
    int dp[1002];
    int minCostClimbingStairs(vector<int>& cost) {
        memset(dp, -1, sizeof(dp));

        return minCost(cost, cost.size());

    }

    int minCost(vector<int>& cost, int n)
    {
        if(n<0)
            return INT_MAX;

        if(n<2)
            return cost[n];

        if(dp[n]!=-1)
            return dp[n];

        if(n!=cost.size())
            dp[n] = min(minCost(cost, n-1), minCost(cost, n-2)) + cost[n];
        else
            dp[n] = min(minCost(cost, n-1), minCost(cost, n-2));

        return dp[n];
    }
};
