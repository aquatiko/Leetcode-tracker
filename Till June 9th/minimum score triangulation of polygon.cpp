
class Solution {
public:
    int dp[51][51]={};
    int minScoreTriangulation(vector<int>& a) {
        return solve(a, 0,a.size()-1);
    }
    int solve(vector<int> &a, int l ,int r)
    {
        if(r-l == 2)
        return a[l]*a[r-1]*a[r];
        if(r-l<2)
            return 0;

        if(dp[l][r]!=0)
            return dp[l][r];

        int tmp_ans = INT_MAX;

        for(int i=l+1;i<r;++i)
        {
            tmp_ans = min(tmp_ans, solve(a, l,i) + solve(a,i,r) + a[l]*a[r]*a[i]);
        }
        return dp[l][r] = tmp_ans;
    }
};

// MCM based question. Tuff to intutively come up with the logic. Very interseting variation of MCM.
