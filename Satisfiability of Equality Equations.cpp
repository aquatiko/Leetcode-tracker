class Solution {
public:
    char findRoot (unordered_map<char, char> &root, char i)
    {
        while(root[ i ] != i)
        {
            root[ i ] = root[ root[ i ] ] ;
            i = root[ i ];
        }
    return i;
    }
    void doUnion(unordered_map<char, char> &root, unordered_map<char, int> &size, char A, char B)
    {
        char root_A = findRoot(root,A);
        char root_B = findRoot(root,B);
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
    void initalize(unordered_map<char, char> &root, unordered_map<char, int> &size, vector<string> &equations)
    {
        for(int i=0;i<equations.size();i++)
        {
            root[equations[i][0]] = equations[i][0];
            size[equations[i][0]] = 1;
            root[equations[i][3]] = equations[i][3];
            size[equations[i][3]] = 1;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        unordered_map<char, char> root;
        unordered_map<char, int> size;
        initalize(root, size, equations);

        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='!')
                continue;
            if(findRoot(root,equations[i][3]) != findRoot(root, equations[i][0]))
            doUnion(root, size,equations[i][0],equations[i][3]);
        }

        for(int i=0;i<equations.size();i++)
        {
            if(equations[i][1]=='=')
                continue;
            if(findRoot(root,equations[i][3]) == findRoot(root, equations[i][0]))
                return false;
        }
        return true;
    }
};
