class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> hash;

        for(int i=0;magazine[i]!=NULL;i++)
        {
            if(hash.find(magazine[i])!=hash.end())
                hash[magazine[i]]++;
            else
                hash[magazine[i]] = 1;
        }

        for(int i=0;ransomNote[i]!=NULL;i++)
        {
            if(hash.find(ransomNote[i]) == hash.end() || hash[ransomNote[i]] == 0)
                return false;

            hash[ransomNote[i]]--;
        }
        return true;
    }
};
