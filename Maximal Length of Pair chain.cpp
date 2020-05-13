static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        if(pairs.size()==0)
            return 0;
        sort(pairs.begin(), pairs.end());

        int dp[pairs.size()];
        dp[0] = 1;
        int ans = 1;
        for(int i=1;i<pairs.size();i++)
        {
            int tmp_ans = 1;
            for(int j=i-1;j>=0;j--)
            {
                if(pairs[i][0]>pairs[j][1])
                    tmp_ans = max(tmp_ans, 1+dp[j]);
                else
                    tmp_ans = max(tmp_ans, dp[j]);
            }
            dp[i] = tmp_ans;

            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

// O(n^2) T and O(n^2) S.   D.F.S with 2D D.P
// O(n^2) T and O(n) S      Bottom Up with 1D D.P
// O(nlogn) T and O(n) S     Greedy
