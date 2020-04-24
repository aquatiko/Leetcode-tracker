class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle == "")
            return 0;
        if(haystack == "")
            return -1;

        int found = haystack.find(needle);

        if(found == string::npos)
            return -1;
        else
            return found;
    }
};

// Without lib function, KMP should be used.
