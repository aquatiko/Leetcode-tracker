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
    int countServers(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> root(m*n), size(m*n);
        initalize(root, size);

        for(int i=0;i<m;i++)
        {
            int lastc = -1;
            for(int j=0;j<n;j++)
            {
                if(lastc == -1 && grid[i][j]==1)
                    lastc = j;
                else if(lastc!=-1 && grid[i][j]==1)
                {
                    if(findRoot(root, i*n+lastc)!=findRoot(root, i*n+j))
                    doUnion(root, size, i*n+lastc, i*n+j);
                    lastc = j;
                }
            }
        }

        for(int i=0;i<n;i++)
        {   int lastr = -1;
            for(int j=0;j<m;j++)
            {
                if(grid[j][i]== 1 && lastr == -1)
                    lastr = j;
                else if(grid[j][i] == 1 && lastr!=-1)
                {
                    if(findRoot(root, i+lastr*n)!=findRoot(root, i+j*n))
                        doUnion(root, size, i+lastr*n, i+j*n);
                    lastr = j;

                }
            }
        }

        int ans = 0;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(findRoot(root, i*n+j) == i*n+j && size[i*n+j]>1)
                    ans+=size[i*n+j];
                //cout<<root[i+j]<<":"<<size[i+j]<<"   ";
            }
            //cout<<endl;
        }
        return ans;
    }
};

// DSU way
