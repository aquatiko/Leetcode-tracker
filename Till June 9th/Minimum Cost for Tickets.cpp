class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {

        vector<int> dp(days.size(), -1);

        solve(days, costs, dp, 0, 0);

        return dp[0];
    }

    int solve(vector<int> &days, vector<int> &costs, vector<int> &dp, int pos, int days_valid)
    {
        if(pos>=days.size())
            return 0;

        if(days[pos]<=days_valid)
            return solve(days, costs, dp, pos+1, days_valid);

        if(pos == days.size()-1 && days_valid>=days[pos])
            return dp[pos] = 0;

        if(dp[pos]!=-1)
            return dp[pos];

        int one_day = costs[0] + solve(days, costs, dp, pos+1, days[pos]);
        int seven_day = costs[1] + solve(days, costs, dp, pos+1, days[pos]+6);
        int thirty_day = costs[2] + solve(days, costs, dp, pos+1, days[pos]+29);

        return dp[pos] = min(one_day, min(seven_day, thirty_day));
    }
};

// Stair climbing variant
