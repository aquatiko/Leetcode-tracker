static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;

        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++)
        {
            if(i-1>=0 && nums[i] == nums[i-1])
                continue;
            for(int j=i+1;j<nums.size();j++)
            {
                if(j-1>i && nums[j]==nums[j-1])
                    continue;
                int ptrfront = j+1, ptrback = nums.size()-1;

                while(ptrfront<ptrback)
                {
                    if(nums[i]+nums[j]+nums[ptrfront]+nums[ptrback] == target)
                    {
                        ans.push_back({nums[i],nums[j],nums[ptrfront],nums[ptrback]});

                        while(ptrfront+1<nums.size() && nums[ptrfront] == nums[ptrfront+1])
                            ptrfront++;
                        ptrfront++;

                        while(ptrback-1 >= 0 && nums[ptrback] == nums[ptrback-1])
                            ptrback--;
                        ptrback--;
                    }
                    else if(nums[i]+nums[j]+nums[ptrfront]+nums[ptrback] < target)
                        ptrfront++;
                    else
                        ptrback--;
                }
            }
        }
        return ans;
    }
};


// Understanding how to avoid duplicate entries is a very key insight from this question.
