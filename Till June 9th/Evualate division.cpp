class Solution {
public:
    unordered_map<string, vector<pair<string, double>>> mp;
    double res;
    vector<double> calcEquation(vector<vector<string>>& eq, vector<double>& values, vector<vector<string>>& queries) {

        for(int i=0;i<eq.size();i++)
        {
            mp[eq[i][0]].push_back({eq[i][1], values[i]});
            mp[eq[i][1]].push_back({eq[i][0], (double)1/values[i]});
        }

        vector<double> ans;
        int n = mp.size();
        for(int i=0;i<queries.size();i++)
        {
            unordered_set<string> visited;
            if(mp.find(queries[i][0])==mp.end() || mp.find(queries[i][1])==mp.end())
            {ans.push_back(-1.0); continue;}
            double res = dfs(visited, queries[i][0], queries[i][1],1.0);
            if(res == INT_MAX)
                ans.push_back(-1.0);
            else
            ans.push_back(res);
        }
        return ans;
    }

    double dfs(unordered_set<string> &visited, string curr, string target, double prod)
    {
        if(curr == target)
            return prod;
        if(visited.find(curr)!=visited.end())
            return INT_MAX;
        visited.insert(curr);
        double tmp_ans = INT_MAX;
        for(int i=0;i<mp[curr].size();i++)
        {
            if(visited.find(mp[curr][i].first)==visited.end())
            {
                double res = dfs(visited, mp[curr][i].first, target, prod*mp[curr][i].second);
                if(res!=INT_MAX)
                    tmp_ans = res;
            }
        }
        return tmp_ans;
    }
};
