class Solution {
public:
    int ans;
    int countSubstrings(string s) {
        ans = 0;

        for(int i=0;s[i]!=NULL;i++)
        {
            ans += check_odd(s, i);
            ans += check_even(s, i);
        }
        return ans;
    }

    int check_odd(string s, int pos)
    {
        int tmp_ans = 1;

        for(int i=1;pos-i>=0 && pos+i<s.length();i++)
        {
            if(s[pos-i] == s[pos+i])
                tmp_ans++;
            else
                break;
        }
        return tmp_ans;
    }

    int check_even(string s, int pos)
    {
        int tmp_ans = 0;

        for(int i=1;pos-i+1>=0 && pos+i<s.length();i++)
        {
            if(s[pos-i+1] == s[pos+i])
                tmp_ans++;
            else
                break;
        }
        return tmp_ans;
    }
};
