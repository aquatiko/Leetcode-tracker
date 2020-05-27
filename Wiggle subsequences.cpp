class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int n = nums.size();
        int dp[n][2];
        dp[0][0] = 1;
        dp[0][1] = 1;
        for(int i=1;i<n;i++)
        {   int lower = 0;
            int higher = 0;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i] && lower<dp[j][0])
                    lower = dp[j][0];
                if(nums[j]>nums[i] && higher<dp[j][1])
                    higher = dp[j][1];
            }
            dp[i][1] = lower+1;
            dp[i][0] = higher+1;
            //cout<<i<<" "<<dp[i][0]<<" "<<dp[i][1]<<"\t";
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

// O(n^2) approach. Could be optimized better. LIS pattern.
// Below is the most optimized version.

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int n = nums.size();

        int idxl = 0, idxh = 0;
        int ansh = 1, ansl=1;
        for(int i=1;i<n;i++)
        {
            int ans1=1, ans2=1;
            if(nums[i]<nums[idxh])
                ans1 = ansh+1;
            if(nums[i]>nums[idxl])
                ans2 = ansl+1;

            if(ans1>ansl)
            {ansl = ans1; idxl = i;}
            else if(ans1==ansl)
            idxl = nums[i]<nums[idxl] ? i : idxl;

            if(ans2>ansh)
            {ansh = ans2; idxh = i;}
            else if(ans2==ansh)
            idxh = nums[i]>nums[idxh] ? i : idxh;
        }
        return max(ansl, ansh);
    }
};

// I was able to come up with this logic only afer knowing that shuch complexity solution exists and I just have to figure how.
