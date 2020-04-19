class Solution {
public:
    string longestPalindrome(string s) {
        if(s == "")
            return "";

        int ans = 1;
        string best="";

        for(int i=0;s[i]!='\0';i++)
        {
            int currAns = 1;
            for(int j=1; i-j>=0 && i+j<s.length();j++)
            {
                if(s[i-j]!=s[i+j])
                    break;
                else
                    currAns+=2;
            }
            if(ans<currAns)
            {
                best = s.substr(i-(currAns/2), currAns);
                ans = currAns;
            }

            currAns = 0;
            for(int j=0;i-j>=0 && i+j+1<s.length();j++)
            {
                if(s[i-j]!=s[i+j+1])
                    break;
                else
                    currAns+=2;
            }
            if(ans<currAns)
            {
                best = s.substr(i-(currAns/2)+1, currAns);
                ans = currAns;
            }
        }
        if(best=="")
            return best+s[0];
        return best;
    }
};

// WAs caused due to submission without checking edges cases.
// Could write more cleaner than this by modularity
