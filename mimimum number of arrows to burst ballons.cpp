static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        return a[1]<b[1];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if(points.size()==0)
            return 0;

        sort(points.begin(),points.end(),compare);
        int last = points[0][1];
        int ans = 1;
        for(int i=1;i<points.size();i++)
        {
            if(points[i][0]>last)
            {
                ans++;
                last = points[i][1];
            }
        }
        return ans;
    }
};
// similar to activity selection problem/methodology
