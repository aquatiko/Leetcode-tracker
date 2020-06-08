class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n ,vector<bool> (n,false));
        int ans = 0;
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    visited[i][j] = true;
                    if(j+1<n && grid[i][j+1]==0)
                    {
                        visited[i][j+1] =true;
                        grid[i][j+1] = 2;
                        q.push({i,j+1});
                        ans = 2;
                    }
                    if(i+1<n && grid[i+1][j]==0)
                    {
                        visited[i+1][j] =true;
                        grid[i+1][j] = 2;
                        q.push({i+1,j});
                        ans = 2;
                    }
                    if(j-1>=0 && grid[i][j-1]==0)
                    {
                        visited[i][j-1] =true;
                        grid[i][j-1] = 2;
                        q.push({i,j-1});
                        ans = 2;
                    }
                    if(i-1>=0 && grid[i-1][j]==0)
                    {
                        visited[i-1][j] =true;
                        grid[i-1][j] = 2;
                        q.push({i-1,j});
                        ans = 2;
                    }
                }
            }
        }

        while(q.size())
        {
            pair<int,int> top = q.front();
            int i = top.first, j = top.second;
            q.pop();
            ans = max(ans, grid[i][j]);
            if(j+1<n && grid[i][j+1]==0)
            {
                visited[i][j+1] =true;
                grid[i][j+1] = grid[i][j]+1;
                q.push({i,j+1});
            }
            if(i+1<n && grid[i+1][j]==0)
            {
                visited[i+1][j] =true;
                grid[i+1][j] = grid[i][j]+1;
                q.push({i+1,j});
            }
            if(j-1>=0 && grid[i][j-1]==0)
            {
                visited[i][j-1] =true;
                grid[i][j-1] = grid[i][j]+1;
                q.push({i,j-1});
            }
            if(i-1>=0 && grid[i-1][j]==0)
            {
                visited[i-1][j] =true;
                grid[i-1][j] = grid[i][j]+1;
                q.push({i-1,j});
            }
        }
        return ans-1;
    }
};

// Can be solved with BFS(best), DFS, Flyod-Warshall
