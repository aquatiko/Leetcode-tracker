class Solution {
public:
    int numJewelsInStones(string j, string s) {
        unordered_set<char> hash;
        for(int i=0;j[i]!='\0';i++)
            hash.insert(j[i]);

        int count = 0;
        for(int i=0;s[i]!='\0';i++)
        {
            if(hash.find(s[i])!=hash.end())
                count++;
        }
        return count;
    }
};
