#include<algorithm>
class Solution {
public:
    double knightProbability(int n, int k, int r, int c) {
        vector<vector<vector<double>>>dp(n+1, vector<vector<double>>(n+1, vector<double>(k+1, -1)));
        return nightProbability(dp, n,k,r,c);
    }
    double nightProbability(vector<vector<vector<double>>> &dp,int n, int k, int r, int c) {
        if(r<0 || r>=n || c<0 || c>=n)
            return 0.0;

        if(k==0)
            return 1.0;
        if(k==1)
        {
            return current_valid_moves(n,r,c)/8;
        }
        if(dp[r][c][k]!=-1)
            return dp[r][c][k];

        return dp[r][c][k] = (nightProbability(dp,n,k-1,r-2,c-1)+nightProbability(dp,n,k-1,r-2,c+1)+nightProbability(dp,n,k-1,r+2,c-1)+nightProbability(dp,n,k-1,r+2,c+1)+nightProbability(dp,n,k-1,r-1,c-2)+nightProbability(dp,n,k-1,r+1,c-2)+nightProbability(dp,n,k-1,r-1,c+2)+nightProbability(dp,n,k-1,r+1,c+2))/8;
    }

    double current_valid_moves(int n,int r,int c)
    {
        double count =0;
        if(r-2>=0 && c-1>=0)
            count++;
        if(r-2>=0 && c+1<n)
            count++;
        if(r+2<n && c-1>=0)
            count++;
        if(r+2<n && c+1<n)
            count++;
        if(r-1>=0 && c-2>=0)
            count++;
        if(r+1<n && c-2>=0)
            count++;
        if(r-1>=0 && c+2<n)
            count++;
        if(r+1<n && c+2<n)
            count++;

        return count;
    }
};

// Implementation was a bit tedious
