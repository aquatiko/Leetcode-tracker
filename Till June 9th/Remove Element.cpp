class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int toPlace = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]!=val)
                nums[toPlace++] = nums[i];
        }
        return toPlace;
    }
};
