static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
        vector<vector<int>> ans(mat.size(), vector<int>(mat[0].size()));

        for(int i=0;i<mat.size();i++)
            for(int j = 1;j<mat[0].size();j++)
                mat[i][j] += mat[i][j-1];


        for(int i=0;i<mat.size();i++)
            for(int j=0;j<mat[0].size();j++)
                ans[i][j] = solve(mat, i, j, k);

        return ans;
    }

    int solve(vector<vector<int>> &mat, int x, int y, int k)
    {
        int sum = 0;
        int rows = mat.size();

        for(int i= max(0, x-k);i<= min(x+k, rows-1);i++)
        {
            int columns = mat[0].size();
            sum += mat[i][min(columns-1, y+k)] - mat[i][max(0, y-k)];

            if(max(0, y-k) == 0)
                sum += mat[i][0];
            else
                sum += mat[i][y-k] - mat[i][y-k-1];
        }
        return sum;
    }
};

// O(n^3) solution. O(n^2) solution is a genralized version of prefix sum array (to matrix).
