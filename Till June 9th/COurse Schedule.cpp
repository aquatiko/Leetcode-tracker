class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& preq) {
        vector<vector<int>> g(n);
        for(int i=0;i<preq.size();i++)
        {
            g[preq[i][0]].push_back(preq[i][1]);
        }

        vector<int> visited(n, -1);
        bool res = true;
        for(int i=0;i<n;i++)
            if(visited[i]==-1)
                res&=findCycle(g, visited,i);
        return res;
    }
    bool findCycle(vector<vector<int>> &g, vector<int> &visited, int curr)
    {
        bool res = true;
        visited[curr] = 0;
        for(int i=0;i<g[curr].size();i++)
        {
            if(visited[g[curr][i]]==0)
                return false;
            else if(visited[g[curr][i]]!=-1)
                res&= findCycle(g, visited, g[curr][i]);
        }
        visited[curr] = 1;
        return res;
    }
};

// Finding cycle in DAG. Use of -1,0,1 for visited array to denote, unvisited, visiting, visited nodes.
