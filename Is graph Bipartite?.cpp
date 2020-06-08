class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.size()==0 || (graph.size()==1 && graph[0].size()==0))
            return true;
        int n = graph.size();
        vector<int> group(graph.size(), 0);
        vector<bool> visited(n, false);

        for(int i=0;i<n;i++)
        {
            if(visited[i] || graph[i].size()==0)
                continue;
            queue<int> q;
            q.push(i);
            group[q.front()] = 1;

            visited[q.front()] = true;
            while(q.size())
            {
                int top = q.front();
                q.pop();
                //cout<<top<<" ";
                for(int i=0;i<graph[top].size();i++)
                {
                    if(group[graph[top][i]]==0 && !visited[graph[top][i]])
                    {q.push(graph[top][i]); group[graph[top][i]] = group[top]==1?2:1; visited[graph[top][i]] = true;}
                    else if(group[top]==group[graph[top][i]])
                        return false;
                }
            }
        }
        return true;
    }
};
