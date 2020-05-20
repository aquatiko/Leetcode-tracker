static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        sort(nums.begin(),nums.end());
        vector<int> dp(nums.size()+1, -1);
        return solve(nums, dp, nums.size()-1);
    }
    int solve(vector<int> &nums, vector<int> &dp, int pos)
    {
        if(pos<0)
            return 0;
        if(dp[pos]!=-1)
            return dp[pos];

        int i=pos-1;
        int count = 1;
        while(i>=0 && nums[i]>=nums[pos]-1)
        {
            if(nums[i] == nums[pos])
                count++;
            i--;
        }

        return dp[pos] = max(nums[pos]*count + solve(nums, dp, i), solve(nums,dp, pos-1));
    }
};

// O(nlogn) time and O(n) complexity
// the bottleneck sorting of nlogn can be avoided and we can do a radix sort of O(n) on given range 1-1000 and then apply dp on buckets.
