class Solution {
public:
    vector<int> ans;
    vector<int> numsSameConsecDiff(int n, int k) {
        if(n==1)
            ans.push_back(0);
        for(int i=1;i<=9;i++)
            solve(n-1,k,i,i);

        return ans;
    }
    void solve(int n, int k, int last_digit, int number)
    {
        if(n<=0)
        {
            ans.push_back(number);
            return;
        }

        if(last_digit+k<=9)
            solve(n-1, k, last_digit+k, number*10 + last_digit+k);
        if(last_digit-k>=0 && k!=0)
            solve(n-1, k, last_digit-k, number*10+last_digit-k);
    }
};
// Simple dfs based solution
