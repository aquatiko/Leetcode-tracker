class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0)
            return 0;
        vector<vector<int>> ans(grid.size(), vector<int> (grid[0].size(), -1));

        greedyDfs(ans,grid, 0,0);

        return ans[0][0];
    }

    void greedyDfs(vector<vector<int>>& ans, vector<vector<int>>& grid, int x, int y)
    {
        if(x<0 || y<0 || x>=grid.size() || y>=grid[0].size())
            return;
        if(x == grid.size()-1 && y == grid[0].size()-1)
        {
            ans[x][y] = grid[x][y];
            return;
        }
        if(ans[x][y]!=-1)
            return;
        greedyDfs(ans,grid, x+1, y);
        greedyDfs(ans, grid, x, y+1);

        if(x+1>=grid.size())
            ans[x][y] = grid[x][y] + ans[x][y+1];
        else if(y+1>=grid[0].size())
            ans[x][y] = grid[x][y] + ans[x+1][y];
        else
            ans[x][y] = grid[x][y] + min(ans[x+1][y], ans[x][y+1]);
    }
};

// Small errors and negligence and cause cumberstone debugging. Be carefull with the edge cases while writing for the first time.
