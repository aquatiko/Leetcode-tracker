class Solution {
public:
    vector<int> gardenNoAdj(int N, vector<vector<int>>& paths) {
        vector<vector<int>> g(N+1);
        for(int i=0;i<paths.size();i++)
        {
            g[paths[i][0]-1].push_back(paths[i][1]-1);
            g[paths[i][1]-1].push_back(paths[i][0]-1);
        }
        vector<int> ans(N, 0);
        ans[0] = 1;
        for(int i=1;i<N;i++)
        {
            bool choice[5];
            memset(choice, false, sizeof(choice));
            for(int j = 0;j<g[i].size();j++)
            {
                if(g[i][j]<i)
                    choice[ans[g[i][j]]] = true;
            }
            for(int j=1;j<=4;j++)
                if(choice[j]==false)
                {ans[i] = j; break;}
        }
        return ans;
    }
};
