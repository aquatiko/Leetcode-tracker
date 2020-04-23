class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int best = INT_MAX;
        int ans;

        for(int i=0;i<nums.size();i++)
        {
            int ptrfront = i+1, ptrback = nums.size()-1;

            while(ptrfront<ptrback)
            {
                if(abs(nums[i]+nums[ptrfront]+nums[ptrback] - target) < best)
                {
                    best = abs(nums[i]+nums[ptrfront]+nums[ptrback] - target);
                    ans = nums[i]+nums[ptrfront]+nums[ptrback];
                }

                if(nums[i]+nums[ptrfront]+nums[ptrback] == target)
                    return target;
                else if(nums[i]+nums[ptrfront]+nums[ptrback] < target)
                    ptrfront++;
                else
                    ptrback--;
            }
        }
        return ans;
    }
};
