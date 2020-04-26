class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        int start = 0, end = nums.size()-1;

        int left=-1, right=-1;

        while(start<=end)
        {
            int mid = (start+end)/2;

            if(nums[mid] == target && ((mid-1>=0 && nums[mid-1]!=nums[mid]) || mid == 0))
               {
                   left = mid;
                   break;
               }
            else if(nums[mid]<target)
               start = mid+1;
            else
               end = mid-1;
        }

        start = 0, end = nums.size()-1;

        while(start<=end)
        {
            int mid = (start+end)/2;

            if(nums[mid] == target && ((mid+1<nums.size() && nums[mid+1]!=nums[mid]) || mid == nums.size()-1))
               {
                   right = mid;
                   break;
               }
            else if(nums[mid]>target)
               end = mid-1;
            else
               start = mid+1;
        }

        return {left,right};
    }
};
