class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.size() == 0)
            return 0;
        int best = 0;
        int m = matrix.size(), n = matrix[0].size();
        int ans[m][n];

        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
            {if(i == 0 || j == 0)
                    ans[i][j] = matrix[i][j] - '0';
                if(matrix[i][j] == '1')
                    best = 1;
            }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j] == '0')
                    ans[i][j] = 0;
                else
                {
                    ans[i][j] = min(ans[i-1][j], min(ans[i-1][j-1], ans[i][j-1])) + 1;
                }

                best = max(best, ans[i][j]);
            }
        }

        return best*best;
    }
};

// Need to check each line for possible bugs before submitting in high stakes contest.
