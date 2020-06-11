class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int ans = 0;
        vector<bool> visited(n+1, false);
        vector<vector<pair<int,int>>> g(n+1);
        vector<int> stamp(n+1, INT_MAX);
        for(int i=0;i<times.size();i++)
        {
            g[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        dfs(g,stamp,visited, k, 0);

        for(int i=1;i<=n;i++)
        {
            if(!visited[i])
                return -1;
            ans = max(ans, stamp[i]);
        }
        return ans;
    }

    void dfs(vector<vector<pair<int,int>>> &g,vector<int> &stamp, vector<bool> &visited, int curr, int time)
    {
        visited[curr] = true;
        stamp[curr] = time;
        for(int i=0;i<g[curr].size();i++)
        {
            if(visited[g[curr][i].first] && stamp[g[curr][i].first]<=time+g[curr][i].second)
                continue;
            dfs(g,stamp, visited, g[curr][i].first, time+g[curr][i].second);
        }
    }
};
