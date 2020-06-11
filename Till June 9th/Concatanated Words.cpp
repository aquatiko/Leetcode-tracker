static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    unordered_set<string> mp;
    static bool compare(string a, string b)
    {
        return a.length()<b.length();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size()==0)
            return {};
        sort(words.begin(),words.end(),compare);
        vector<string> ans;

        for(auto str:words)
        {
            if(str.length()>0 && check(str,0))
                ans.push_back(str);
            mp.insert(str);
        }
        return ans;
    }
    bool check(string s, int pos)
    {
        if(pos>=s.length())
            return true;
        string tmp = "";
        for(int i = pos;i<s.length();i++)
        {
            tmp+=s[i];
            if(mp.find(tmp)!=mp.end() && check(s, i+1))
                return true;
        }
        return false;
    }
};

// Below is a D.P memozization version of above code. More faster.
class Solution {
public:
    unordered_set<string> mp;
    static bool compare(string a, string b)
    {
        return a.length()<b.length();
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        if(words.size()==0)
            return {};
        sort(words.begin(),words.end(),compare);
        vector<string> ans;

        for(auto str:words)
        {
            if(str.length()>0 && check(str,0))
                ans.push_back(str);
            mp.insert(str);
        }
        return ans;
    }
    bool check(string s, int pos)
    {
        if(pos>=s.length())
            return true;
        if(mp.find(s.substr(pos))!=mp.end())
            return true;
        string tmp = "";
        for(int i = pos;i<s.length();i++)
        {
            tmp+=s[i];
            if(mp.find(tmp)!=mp.end() && check(s, i+1))
            {mp.insert(s.substr(pos));return true;}
        }
        return false;
    }
};
