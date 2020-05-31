class Solution {
public:
    long long int dp[51][51][51];
    int findPaths(int m, int n, int N, int i, int j) {
        memset(dp,-1,sizeof(dp));
        return solve(m,n,N,i,j);
    }
    long long int solve(int m,int n, int N, int i, int j)
    {
        if(i<0 || j<0 || i>=m || j>=n)
        {return 1;}
        if(N==0)
            return 0;
        if(dp[i][j][N]!=-1)
            return dp[i][j][N];

        return dp[i][j][N] = (solve(m,n,N-1,i+1,j) + solve(m,n,N-1,i,j+1) + solve(m,n,N-1,i-1,j) + solve(m,n,N-1,i,j-1))%(1000000007);
    }
};
