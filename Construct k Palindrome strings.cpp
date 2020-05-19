static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    bool canConstruct(string s, int k) {
        if(k>s.length())
            return false;
        if(k==s.length())
            return true;
        int count[26]={};
        for(int i=0;s[i]!=NULL;i++)
            count[s[i]-'a']++;

        int check = 0;
        for(int i=0;i<26;i++)
            if(count[i]%2!=0)
                check++;
        if(check>k)
            return false;
        return true;

    }
};
