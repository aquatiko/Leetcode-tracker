class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> g(n, vector<int> (n ,INT_MAX));

        for(int i=0;i<edges.size();i++)
        {
            g[edges[i][0]][edges[i][1]] = edges[i][2];
            g[edges[i][1]][edges[i][0]] = edges[i][2];
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                for(int k=0;k<n;k++)
                {

                    if(g[j][i] == INT_MAX || g[i][k]==INT_MAX || i==j || i==k || j==k)
                        continue;
                    g[j][k] = min(g[j][k], g[j][i]+g[i][k]);

                }
            }
        }

        int mini = INT_MAX, ans = -1;

        for(int i=0;i<n;i++)
        {
            int count = 0;
            for(int j=0;j<n;j++)
                if(g[i][j]<=distanceThreshold)
                    count++;

            if(count<=mini)
            {mini = count; ans = i;}
        }
        return ans;
    }
};
