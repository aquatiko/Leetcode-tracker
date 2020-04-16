class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans(nums.size());

        int reccuringSum = 1;

        for(int i=0;i<nums.size();i++)
        {
            ans[i] = reccuringSum;
            reccuringSum*=nums[i];
        }

        reccuringSum = 1;

        for(int i = nums.size()-1;i>=0;i--)
        {
            ans[i] *= reccuringSum;
            reccuringSum *= nums[i];
        }

        return ans;
    }
};

// AC on 1st try as I've solved question using such approach under such constraint which gave hint of what approach to use.
// Approach is to first calculate product of left halves in first iteration in the ans variable and multiply the right halves in the next iteration in the same ans variable.
