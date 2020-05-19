static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size()%k!=0)
            return false;

        multiset<int> mp;
        for(int i=0;i<nums.size();i++)
            mp.insert(nums[i]);

        while(mp.size())
        {
            int start = *(mp.begin());
            for(int i=start;i<start+k;i++)
            {
                auto itr = mp.find(i);
                if(itr == mp.end())
                    return false;
                mp.erase(itr);
            }
        }
        return true;
    }
};

// logcic was simple but implementation gave a tuff time.
