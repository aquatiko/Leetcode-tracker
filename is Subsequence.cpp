static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int ptrs = s.size()-1, ptrt = t.size()-1;

        while(ptrs>=0 && ptrt>=0)
        {
            if(s[ptrs] == t[ptrt])
            {
                ptrs--;
                ptrt--;
            }
            else
                ptrt--;
        }

        return ptrs==-1;
    }

};
