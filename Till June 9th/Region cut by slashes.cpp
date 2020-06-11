class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        vector<vector<int>> g(n*3, vector<int> (n*3, 1));

        for(int i=0;i<n;i++)
        {
            for(int j = 0;j<n;j++)
            {
                if(grid[i][j]=='/')
                {
                    g[3*i][3*j+2] = 0;
                    g[3*i+1][3*j+1] = 0;
                    g[3*i+2][3*j] = 0;

                }
                else if(grid[i][j] == '\\')
                {
                    g[3*i][3*j] = 0;
                    g[3*i+1][3*j+1] = 0;
                    g[3*i+2][3*j+2] = 0;
                }
            }
        }

        vector<vector<bool>> visited(3*n, vector<bool>(3*n, false));

        int count=0;
        for(int i =0;i<3*n;i++)
        {
            for(int j=0;j<3*n;j++)
            {   if(!visited[i][j] && g[i][j]!=0)
                {
                    count++;
                    dfs(g,visited,i,j);
                }
             //cout<<g[i][j]<<" ";
            }
            //cout<<endl;
        }
        return count;
    }
    void dfs(vector<vector<int>> &g, vector<vector<bool>> &visited, int i, int j)
    {
        if(i<0 || j<0 || i>=g.size() || j>=g.size())
            return;
        if(g[i][j] == 0 || visited[i][j])
            return;
        visited[i][j] = true;

        dfs(g, visited, i+1,j);
        dfs(g, visited, i,j+1);
        dfs(g, visited, i-1,j);
        dfs(g, visited, i,j-1);

    }
};

// The challenge was to identfy graph in this question. Just a dfs on a upscaled grid to visualize the graph.
