class Solution {
public:
    int dp[1002][1002];
    int m_cap;
    int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
        memset(dp, -1, sizeof(dp));
        m_cap = shelf_width;

        return solve(books, 0, 0, 0);
    }

    int solve(vector<vector<int>> &books, int capacity, int pos, int height)
    {
        if(pos == books.size())
            return height;

        if(dp[pos][capacity]!=-1)
            return dp[pos][capacity];

        if(capacity + books[pos][0] > m_cap)
            return dp[pos][capacity] = height + solve(books, books[pos][0], pos+1, books[pos][1]);

        return dp[pos][capacity] = min(solve(books, capacity + books[pos][0], pos+1, max(height, books[pos][1])), height + solve(books, books[pos][0], pos+1, books[pos][1]));

    }
};

// Wrote exact DP code with 1D DP but gave WA. Couldn't figure out when to use 2D dp.
// Deciding number of states?
// knapsack or DFS D.P
