static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    vector<int> numOfBurgers(int ts, int cs) {
        if((4*cs -ts)<0 || (4*cs - ts)%2 != 0 || (cs < (4*cs - ts)/2))
            return {};

        return {cs - ((4*cs - ts)/2), (4*cs - ts)/2};
    }
};
