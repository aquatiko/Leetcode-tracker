static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int findContentChildren(vector<int>& s, vector<int>& g) {
        int ans = 0;
        int ptrs=0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

        for(int i=0;i<g.size() &&ptrs<s.size();i++)
        {
            if(g[i]>=s[ptrs])
            {
                ans++;
                ptrs++;
            }
        }
        return ans;
    }
};

// The intution is to feed the lest greediest child first while iterating over the size of cookies in increasing order.
