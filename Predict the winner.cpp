static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int dp[21][21][2];
    bool PredictTheWinner(vector<int>& nums) {
        memset(dp, -1, sizeof(dp));
        int ans = solve(nums,0,nums.size()-1, true);
        if(ans<0)
            return false;
        else
            return true;
    }
    int solve(vector<int> &nums, int left, int right, bool chance)
    {
        if(left==right && chance)
            return nums[left];
        else if(left==right && !chance)
            return -nums[left];

        if(dp[left][right][chance]!=-1)
            return dp[left][right][chance];

        if(chance)
            return dp[left][right][chance] = max(nums[left] + solve(nums, left+1, right, false), nums[right] + solve(nums, left, right-1, false));
        else
            return dp[left][right][chance] = min(-nums[left] + solve(nums, left+1, right, true), -nums[right] + solve(nums, left, right-1, true));
    }
};

// From below to above as final submission.

// class Solution {
// public:
//     bool PredictTheWinner(vector<int>& nums) {
//         return solve(nums,0,nums.size()-1,0,0, true);
//     }
//     bool solve(vector<int> &nums, int left, int right, int p1, int p2,bool chance)
//     {
//         if(left>right)
//             return p1>=p2;
//
//         if(chance)
//             return solve(nums, left+1, right,p1+nums[left],p2, false) | solve(nums, left, right-1, p1+nums[right],p2, false);
//         else
//             return solve(nums, left+1, right,p1, p2+nums[left], true) & solve(nums, left, right-1, p1, p2+nums[right], true);
//     }
// };

// Could easily write recursive code with lots of state spaces(parameters) but then it bacame hard to memoize. But that solution was AC.
// I was using two sepearte variables to keep scores of each player, using a single variable and negative score domain gave some hints.
// Then tried further to memoize but still I was stuck as the return type was bool, I realized I dont need my solve function to make micro decisons
// I can decide who wins or looses in the main function, i.e I misjudged on the return parameters and it became a big logical error.
// Tip: Backtrack your ideas and thinking process too, write it down (memoize) if your memory limits are small ;)
