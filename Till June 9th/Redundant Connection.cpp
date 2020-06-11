class Solution {
public:
    int findRoot (vector<int> &root ,int i)
    {
        while(root[ i ] != i)
        {
            root[ i ] = root[ root[ i ] ] ;
            i = root[ i ];
        }
    return i;
    }
    void doUnion(vector<int> &root,vector<int> &size,int A,int B)
    {
        int root_A = findRoot(root,A);
        int root_B = findRoot(root,B);
        if(size[root_A] < size[root_B ])
        {
            root[ root_A ] = root[root_B];
            size[root_B] += size[root_A];
        }
        else
        {
            root[ root_B ] = root[root_A];
            size[root_A] += size[root_B];
        }
    }
    void initalize(vector<int> &root, vector<int> &size)
    {
        for(int i=0;i<root.size();i++)
        {
            root[i] = i;
            size[i] = 1;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> root(n),size(n);
        initalize(root, size);

        for(int i=0;i<n;i++)
        {
            if(findRoot(root, edges[i][0]-1)!=findRoot(root, edges[i][1]-1))
                doUnion(root, size, edges[i][0]-1, edges[i][1]-1);
            else
                return edges[i];
        }
        return {};
    }
};
