class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d+1][target+1];
        memset(dp, 0, sizeof(dp));

        for(int i=1;i<=min(f,target);i++)
            dp[1][i] = 1;

        for(int i=2;i<=d;i++)
        {
            for(int j=i;j<=target;j++)
            {

                long long tmp_ans = 0;

                for(int k=1;k<=f;k++)
                {
                    if(j-k<=0)
                        break;
                    tmp_ans = (tmp_ans + dp[i-1][j-k])%1000000007;
                }

                dp[i][j] = tmp_ans;
                //cout<<dp[i][j]<<" ";
            }
            //cout<<"\n";
        }

        return dp[d][target]%1000000007;
    }
};
