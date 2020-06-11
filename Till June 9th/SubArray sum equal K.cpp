class Solution {
public:
    unordered_map<int, int> prevSum;
    int ans;
    int subarraySum(vector<int>& nums, int k) {
        ans = 0;
        int currSum = 0;

        for(int i=0;i<nums.size();i++)
        {
            currSum+=nums[i];
            if(currSum == k)
                ans++;

            if(prevSum.find(currSum - k) != prevSum.end())
                ans += prevSum[currSum - k];

            prevSum[currSum]++;
        }
        return ans;
    }
};

// very smart trick used. Just a change of perspective sometimes can help a lot. Try doing that often.
