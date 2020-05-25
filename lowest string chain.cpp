static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    static bool compare(string &a, string &b)
    {
            return a.length()<b.length();
    }
    int longestStrChain(vector<string>& words) {
        int n = words.size();
        vector<int> dp(n,1);
        sort(words.begin(),words.end(), compare);
        int ans = 1;

        for(int i=words.size()-1;i>=0;i--)
        {
            for(int j=i+1;j<words.size() && words[j].length()-words[i].length()<=1;j++)
            {
                if(words[j].length()==words[i].length())
                    continue;
                if(sucessor(words[i],words[j]))
                    dp[i] = max(dp[i], 1+dp[j]);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
    bool sucessor(string a, string b)
    {
        bool flag = false;
        int freq[26]={};
        for(auto i:a)
            freq[i-'a']++;
        for(auto i:b)
        {
            if(freq[i-'a']>0)
                freq[i-'a']--;
            else if(freq[i-'a']==0 && !flag)
            {flag = true;}
            else
                return false;
        }
        return flag;
    }
};
