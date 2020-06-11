class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        if(nums.size()==0)
            return 1;
        if(nums.size()==1 && nums[0]==1)
            return 2;

        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] == i || nums[i]<=0 || nums[i]>=nums.size())
                continue;

            while(nums[i]!=i && nums[i]>0 && nums[i]<nums.size() && nums[nums[i]]!=nums[i])
            {
                swap(nums[i], nums[nums[i]]);
            }
        }

        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=i)
                return i;
        }

        if(nums[0]!=nums.size())
        return nums.size();
        else
            return nums.size()+1;
    }
};

// Approach was know but handling edge cases caused WAs.
