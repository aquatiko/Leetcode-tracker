class Solution {
public:
    unordered_map<int, int> mp;
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        for(int i=0,j=0;s[j]!='\0';j++)
        {
            if(mp.find(s[j]) != mp.end())
                i = max(mp[s[j]],i);

            ans = max(ans, j-i+1);

            mp[s[j]] = j+1;

        }
        return ans;
    }
};

// the whole implementatio is very important and the concept of jumping slow pointer directly is very interesting.
