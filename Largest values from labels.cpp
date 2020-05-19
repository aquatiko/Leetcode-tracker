static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int num_wanted, int use_limit) {
        int ans = 0;
        priority_queue<pair<int,int>> q;
        unordered_map<int,int> label_count;
        for(int i=0;i<labels.size();i++)
            q.push({values[i],labels[i]});
        int taken = 0;
        int last = -1, lastcount =0;
        while(q.size() && taken<num_wanted)
        {
            pair<int,int> top = q.top();
            q.pop();
            if(top.second!=last)
            {
                if(label_count.find(top.second)!=label_count.end() && label_count[top.second]>=use_limit)
                    continue;
                last = top.second;
                taken++;
                lastcount=1;
                ans+=top.first;
                label_count[top.second]++;
            }
            else if(top.second == last && lastcount<use_limit)
            {
                if(label_count.find(top.second)!=label_count.end() && label_count[top.second]>=use_limit)
                    continue;
                taken++;
                lastcount++;
                ans+=top.first;
                label_count[top.second]++;
            }
        }
        return ans;
    }
};
