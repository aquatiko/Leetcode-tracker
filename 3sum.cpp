static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]>0)
                break;
            if(i>0 && nums[i] == nums[i-1])
                continue;

            int ptrfront = i+1, ptrback = nums.size()-1;

            while(ptrfront<ptrback)
            {
                if(nums[i] + nums[ptrfront] + nums[ptrback] == 0)
                {   ans.push_back({nums[i] ,nums[ptrfront] ,nums[ptrback]});

                    int tmp = ptrfront;
                    while(ptrfront<ptrback && nums[tmp] == nums[ptrfront])
                        ptrfront++;

                    tmp = ptrback;
                    while(ptrfront<ptrback && nums[tmp] == nums[ptrback])
                        ptrback--;
                }
                else if(nums[i] + nums[ptrfront] + nums[ptrback] > 0)
                    ptrback--;
                else
                    ptrfront++;

            }
        }

        return ans;
    }
};

// Knowing the O(n^2) time O(1) space approach with most efficient duplicate avoiding algo. is imp.
