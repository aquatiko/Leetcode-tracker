static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int t) {
        vector<vector<int>> dp(clips.size()+1, vector<int> (t+1, -1));
        sort(clips.begin(), clips.end());
        int ans = solve(clips, dp, clips.size()-1, t);

        if(ans >200)
            return -1;
        else
            return ans;
    }

    int solve(vector<vector<int>> &clips, vector<vector<int>> &dp, int pos, int t)
    {
        if(t<=0)
            return 0;
        if(pos<0)
            return INT_MAX/2;

        if(dp[pos][t]!=-1)
            return dp[pos][t];

        return dp[pos][t] = min(solve(clips, dp, pos-1, t), clips[pos][0]<=t && clips[pos][1]>=t ? 1 + solve(clips, dp, pos-1, clips[pos][0]) : INT_MAX);
    }
};

// D.P O(n^2) Time and Space DFS based solution. Can be improved by a greedy approach.
