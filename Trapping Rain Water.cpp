class Solution {
public:
    int trap(vector<int>& nums) {
        if(nums.size()<3)
            return 0;
        vector<int> left, right;

        int maxTillNow = nums[0];
        left.push_back(0);

        for(int i=1;i<nums.size();i++)
        {

            maxTillNow = max(maxTillNow, nums[i]);
            left.push_back(maxTillNow);
        }

        maxTillNow = nums[nums.size()-1];

        right.push_back(nums[nums.size()-1]);

        for(int i=nums.size()-2;i>=0;i--)
        {

            maxTillNow = max(maxTillNow, nums[i]);
            right.push_back(maxTillNow);
        }
        reverse(right.begin(),right.end());

        int ans = 0;

        for(int i=1;i<nums.size()-1;i++)
        {
            ans+= min(left[i],right[i]) - nums[i];
        }
        return ans;
    }
};
