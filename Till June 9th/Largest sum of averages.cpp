static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    double largestSumOfAverages(vector<int>& a, int k) {
        if(a.size()==0)
            return 0;
        vector<vector<double>> dp(k+1, vector<double>(a.size()+1));
        double sum = 0.0;
        for(int i=0;i<a.size();i++)
        {
            sum+=a[i];
            dp[1][i] = sum/(i+1);
        }
        for(int i=2;i<=k;i++)
            dp[i][0] = a[0];

        for(int i=2;i<=k;i++)
        {
            for(int j=1;j<a.size();j++)
            {   double tmp_ans = dp[i-1][j];
                double sum = a[j];
                double count = 1.0;
                for(int p =j-1;p>=0;p--)
                {
                    tmp_ans = max(tmp_ans, dp[i-1][p] + (sum/count));
                    sum+=a[p];
                    count++;
                }
                dp[i][j] = tmp_ans;
            }
        }
        return dp[k][a.size()-1];
    }
};

// Space can be further reduced to O(N) as at any step we require only the last filled row only. Use toggle buttons (flag) to
// implement this.   
