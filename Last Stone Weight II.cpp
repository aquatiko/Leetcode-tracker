class Solution {
public:
    int dp[31][3001];
    int lastStoneWeightII(vector<int>& stones) {
        memset(dp, -1, sizeof(dp));
        return solve(stones, stones.size()-1,0);
    }
    int solve(vector<int> &stones, int pos,int sum)
    {
        if(pos<0)
        return abs(sum);
        if(dp[pos][abs(sum)]!=-1)
            return dp[pos][abs(sum)];

        int choice1 = solve(stones, pos-1, sum-stones[pos]);
        int choice2 = solve(stones, pos-1, sum+stones[pos]);
        return dp[pos][abs(sum)] = min(choice1, choice2);
    }
};

// O(n^2) time and space solution based on 1/0 knapsack;
// realizing that this is a knapsack variation is difficult from the problem statement.
// Dry running hinted the pattern that each element is either getting a +ve or -ve sign at the end to get the final ans.
// After that it was a previously seen problem.

// can be optimized on space complexity using bottom up approach.
