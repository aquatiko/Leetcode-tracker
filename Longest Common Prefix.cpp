class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        sort(strs.begin(),strs.end());

        int i;
        for(i=0;strs[0][i]!='\0';i++)
        {
            if(strs[0][i] != strs[strs.size()-1][i])
                break;
        }
        return strs[0].substr(0, i);
    }
};

// Already knew the approach. But the approach is an interesting one.
