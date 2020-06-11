class Solution {
public:
    vector<string> ans;
    vector<string> generateParenthesis(int n) {
        if(n==0)
            return {};

        solve(n,0,0,"");

        return ans;
    }

    void solve(int n, int opened, int closed, string combination)
    {
        if(opened == n && closed == n)
        {
            ans.push_back(combination);
            return;
        }
        if(opened<n)
        solve(n, opened+1, closed, combination + "(");

        if(closed<opened)
            solve(n, opened, closed+1, combination + ")");

    }

};
