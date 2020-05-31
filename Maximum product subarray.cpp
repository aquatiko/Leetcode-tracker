class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        bool seenzero = nums[0]==0?true:false;
        int n = nums.size();
        long long left[n], right[n];
        left[0] = 1;
        right[n-1] = 1;

        for(int i=1;i<n;i++)
        {
            if(nums[i]==0)
                seenzero = true;
            if(nums[i-1]!=0)
                left[i] = left[i-1]*nums[i-1];
            else
                left[i] = 1;
        }

        for(int i=n-2;i>=0;i--)
        {
            if(nums[i+1]!=0)
                right[i] = right[i+1]*nums[i+1];
            else
                right[i] = 1;
        }

        long long ans = LONG_MIN;

        for(int i=0;i<n;i++)
        {
            long long res = max(left[i]*nums[i], right[i]*nums[i]);
            res = max(res, left[i]*right[i]*nums[i]);
            ans = max(res, ans);
        }

        // if(ans<0 && seenzero == true)
        //     return 0;
        return ans;
    }
};
