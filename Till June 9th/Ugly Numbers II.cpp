class Solution {
public:
    int nthUglyNumber(int n) {
        vector<long long> dp(n+1);
        dp[0] = 1;
        int idx2 = 0, idx3 = 0, idx5 = 0;
        for(int i=1;i<n;i++)
        {
            long long tmp_ans = LONG_MAX;
            tmp_ans = min(tmp_ans, dp[idx2]*2);
            tmp_ans = min(tmp_ans, dp[idx3]*3);
            tmp_ans = min(tmp_ans, dp[idx5]*5);
            if(tmp_ans == dp[idx2]*2)
                idx2++;
            if(tmp_ans == dp[idx3]*3)
                idx3++;
            if(tmp_ans == dp[idx5]*5)
                idx5++;
            dp[i] = tmp_ans;
        }
        return dp[n-1];
    }
};

// This is O(n) time and space aapproach. It is bit difficult to understand the logic of using idx2, idx3, idx5.
// Below approach of O(n^2) time and O(n) space will clear out the confusion.

class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n+1);
        dp[0] = 1;

        for(int i=1;i<n;i++)
        {
            int tmp_ans = INT_MAX;
            for(int j=i-1;j>=0;j--)
            {
                if((long)dp[j]*2<=INT_MAX && dp[j]*2>dp[i-1])
                    tmp_ans = min(tmp_ans, dp[j]*2);
                else if((long)dp[j]*3<=INT_MAX && dp[j]*3>dp[i-1])
                    tmp_ans = min(tmp_ans, dp[j]*3);
                else if((long)dp[j]*5<=INT_MAX && dp[j]*5>dp[i-1])
                    tmp_ans = min(tmp_ans, dp[j]*5);
            }
            dp[i] = tmp_ans;
        }
        return dp[n-1];
    }
};

// Here the inner for loop is optimized(logically) in the first approach.
