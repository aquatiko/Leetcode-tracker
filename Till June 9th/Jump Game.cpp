class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()<2)
            return true;
        int curr = nums[0];
        if(curr == 0)
            return false;

        for(int i=1;i<nums.size();i++)
        {
            curr--;
            if(curr<0)
                return false;

            curr = max(curr, nums[i]);
        }

        return true;
    }
};
