static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    static bool comp(vector<int> &a, vector<int> &b)
    {
        return a[0]-a[1] < b[0]-b[1];
    }
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(),costs.end(),comp);
        int ans = 0;
        for(int i=0;i<costs.size()/2;i++)
            ans+= costs[i][0];
        for(int j=costs.size()/2;j<costs.size();j++)
            ans+=costs[j][1];
        return ans;
    }
};

// Intution usded behind Greedy: fist move everyone to place A, you will get total cost(worst). Now you decide who all people to
// send to B but when you send then to B, they return the money you spent on them and you give them money to travel only from mean
//position. So when you shift your perspective from mean position to A, the solution becomes greddy solvable.
