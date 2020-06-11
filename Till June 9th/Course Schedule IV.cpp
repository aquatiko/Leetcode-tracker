class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& preq, vector<vector<int>>& queries) {
        vector<vector<int>> dist(n, vector<int> (n,INT_MAX));

        for(int i=0;i<preq.size();i++)
            dist[preq[i][0]][preq[i][1]] = 1;
        for(int k=0;k<n;k++)
        {
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]==INT_MAX || dist[k][j]==INT_MAX)
                        continue;
                    if(dist[i][j]>dist[i][k]+dist[k][j])
                        dist[i][j] = dist[i][k]+dist[k][j];
                }
            }
        }

        vector<bool> ans;
        for(int i=0;i<queries.size();i++)
        {
            if(dist[queries[i][0]][queries[i][1]]==INT_MAX)
                ans.push_back(false);
            else
                ans.push_back(true);
        }
        return ans;
    }
};

// Done by floyd-warshall algo of shortest path between each node. Basically we need to check if there exist a path between every pair of vertices; 
