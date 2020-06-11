static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;

        for(int i=0;i<nums.size();i++)
        {
            if(mp.find(target-nums[i])!=mp.end())
                return {i, mp[target-nums[i]]};
            else
                mp.insert({nums[i],i});
        }
        return {};
    }
};

// WA caused due to ingnorance of easy tag. Missed edge cases.
