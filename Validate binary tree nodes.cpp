class Solution {
public:
    bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
        vector<bool> visited(n, false);
        vector<int> indegree(n, 0);
        for(int i=0;i<n;i++)
        {
            if(leftChild[i]!=-1)
                indegree[leftChild[i]]++;
            if(rightChild[i]!=-1)
                indegree[rightChild[i]]++;
        }

        bool res = true;
        for(int i=0;i<n;i++)
            if(indegree[i]==0)
            {res &=dfs(leftChild, rightChild, visited, i); break;}

        for(int i=0;i<n;i++)
            if(visited[i]== false)
                res = false;
        return res;
    }

    bool dfs(vector<int> &leftChild, vector<int> &rightChild, vector<bool> &visited, int pos)
    {
        if(pos>= leftChild.size())
            return true;
        visited[pos] = true;

        if(leftChild[pos]!=-1 && visited[leftChild[pos]] == true)
            return false;
        if(rightChild[pos]!=-1 && visited[rightChild[pos]] == true)
            return false;

        bool res = true;
        if(leftChild[pos]!=-1)
            res &= dfs(leftChild, rightChild, visited, leftChild[pos]);
        if(rightChild[pos]!=-1)
            res &= dfs(leftChild, rightChild, visited, rightChild[pos]);

        return res;
    }
};

// indegree + cycles in DAG concept
