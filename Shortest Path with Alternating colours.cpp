class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& re, vector<vector<int>>& be) {
        vector<vector<pair<int,int>>> g(n);

        for(int i=0;i<re.size();i++)
            g[re[i][0]].push_back({re[i][1],0});
        for(int i=0;i<be.size();i++)
            g[be[i][0]].push_back({be[i][1],1});

        vector<int> ans(n, INT_MAX);
        ans[0] = 0;

        queue<pair<int,int>> q;
        vector<vector<bool>> visited(n, vector<bool> (2,false));
        q.push({0,0});
        visited[0][0] = true;
        while(q.size())
        {
            pair<int,int> top = q.front();
            q.pop();
            ans[top.first] = min(ans[top.first], top.second);

            for(int i=0;i<g[top.first].size();i++)
            {   if(top.second%2==0 && g[top.first][i].second==1 && !visited[g[top.first][i].first][0])
                {
                    q.push({g[top.first][i].first, top.second+1});
                    visited[g[top.first][i].first][0] = true;
                }
                else if(top.second%2==1 && g[top.first][i].second==0 && !visited[g[top.first][i].first][1])
                {
                    q.push({g[top.first][i].first, top.second+1});
                    visited[g[top.first][i].first][1] = true;
                }
            }
        }

        q.push({0,0});
        vector<vector<bool>> visi(n, vector<bool> (2,false));
        visi[0][1] = true;
        while(q.size())
        {
            pair<int,int> top = q.front();
            q.pop();
            ans[top.first] = min(ans[top.first], top.second);

            for(int i=0;i<g[top.first].size();i++)
            {   if(top.second%2==0 && g[top.first][i].second==0 && !visi[g[top.first][i].first][0])
                {
                    q.push({g[top.first][i].first, top.second+1});
                    visi[g[top.first][i].first][0] = true;
                }
                else if(top.second%2==1 && g[top.first][i].second==1 && !visi[g[top.first][i].first][1])
                {
                    q.push({g[top.first][i].first, top.second+1});
                    visi[g[top.first][i].first][1] = true;
                }
            }
        }

        for(int i=0;i<n;i++)
            if(ans[i]==INT_MAX)
                ans[i] = -1;
        return ans;
    }
};
