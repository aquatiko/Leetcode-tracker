class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans = 0;
        int left  = 0;
        for(int i=0;s[i]!=NULL;i++)
        {
            if(s[i]=='(')
                left++;
            else
            {
                if(left>0)
                    left--;
                else
                    ans++;
            }
        }
        ans+=left;
        return ans;
    }
};
