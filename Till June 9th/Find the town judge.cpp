class Solution {
public:
    int findJudge(int N, vector<vector<int>>& trust) {
        vector<int> indegree(N+1, 0);
        vector<int> outdegree(N+1,0);
        for(int i = 0; i<trust.size();i++)
        {
            indegree[trust[i][1]]++;
            outdegree[trust[i][0]]++;
        }
        for(int i=1;i<=N;i++)
            if(indegree[i] - outdegree[i]==N-1 && !seen[i])
                return i;
        return -1;
    }
};


// COncept of indegree and outdegree.
