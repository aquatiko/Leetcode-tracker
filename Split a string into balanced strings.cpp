class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0;
        int countR = 0, countL = 0;
        for(int i=0;s[i]!=NULL;i++)
        {
            if(s[i]=='R')
                countR++;
            else
                countL++;

            if(countR == countL)
            {
                countL = 0;
                countR = 0;
                ans++;
            }
        }
        return ans;
    }
};
