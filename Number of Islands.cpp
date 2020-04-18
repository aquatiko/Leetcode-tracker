class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size()==0)
            return 0;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        int ans = 0;

        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(grid[i][j] == '1' && visited[i][j] == false)
                {
                    ans++;
                    dfs(grid, visited, i, j);
                }
            }
        }

        return ans;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x, int y)
    {
        if(x>=grid.size() || x<0 || y>=grid[0].size() || y<0)
            return;
        if(grid[x][y]=='0' || visited[x][y] == true)
            return;
        visited[x][y] = true;

        dfs(grid, visited, x+1, y);
        dfs(grid, visited, x-1, y);
        dfs(grid, visited, x, y+1);
        dfs(grid, visited, x, y-1);
    }
};
