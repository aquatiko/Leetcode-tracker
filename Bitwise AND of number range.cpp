class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        long long tmp = m;
        for(long long i=(long long)m+1;i<=(long long)n;i++)
        {
            tmp = tmp&i;
            if(tmp == 0)
                return 0;
        }
        return tmp;
    }
};

// Hacked code without complete actual logic. Still works lol.
