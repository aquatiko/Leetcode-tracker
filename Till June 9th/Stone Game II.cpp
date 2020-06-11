class Solution {
public:
    int stoneGameII(vector<int>& arr) {
        int sum[arr.size()];
        sum[arr.size()-1] = arr[arr.size()-1];

        for(int i=arr.size()-2;i>=0;i--)
            sum[i] = sum[i+1] + arr[i];

        int dp[arr.size()][arr.size()+1];

        for(int i=arr.size()-1;i>=0;i--)
        {
            for(int M = 1;M<=arr.size();M++)
            {
                if(2*M >= arr.size()-i)
                {dp[i][M] = sum[i]; continue;}

                int tmp_ans = INT_MAX;
                for(int X=1;X<=2*M && i+X<arr.size();X++)
                {
                    if(2*X>=arr.size())
                        tmp_ans = min(tmp_ans, sum[i+X]);
                    else
                    tmp_ans = min(tmp_ans, dp[i+X][max(M,X)]);
                }

                dp[i][M] = sum[i] - tmp_ans;
            }
        }

        return dp[0][1];
    }
};

// Very tough question for me. Couldn't igure out the approach or how to build up a solution/table/recursion.
// Coded Bottom-up only after loking at a top-down approach.
