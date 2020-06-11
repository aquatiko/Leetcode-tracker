static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> rg(n);
        queue<int> q;
        vector<bool> visited(n,false);
        vector<bool> safe(n, false);
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==0)
            {q.push(i); safe[i] = true;visited[i] = true;}
            for(int j=0;j<graph[i].size();j++)
            {
                rg[graph[i][j]].push_back(i);
            }
        }

        vector<int> ans;


        while(q.size())
        {
            int top = q.front();
            q.pop();
            for(int i = 0;i<rg[top].size();i++)
            {
                if(visited[rg[top][i]])
                    continue;
                bool tmp_safe = true;
                for(int j=0;j<graph[rg[top][i]].size();j++)
                {
                    if(!safe[graph[rg[top][i]][j]])
                    {tmp_safe = false; break;}
                }
                if(tmp_safe)
                {safe[rg[top][i]] = true; q.push(rg[top][i]); visited[rg[top][i]] = true;}
            }
        }
        for(int i=0;i<n;i++)
            if(safe[i])
                ans.push_back(i);
        return ans;
    }
};

// Important question based on edge reversal.
