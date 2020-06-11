class Solution {
public:
    unordered_map<string, vector<string>> mp;
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(int i=0;i<tickets.size();i++)
            mp[tickets[i][0]].push_back(tickets[i][1]);
        for(auto itr:mp)
            sort(mp[itr.first].begin(), mp[itr.first].end(), greater<string>());

        dfs("JFK");
        reverse(ans.begin(),ans.end());
        return ans;
    }
    void dfs(string curr)
    {


        while(mp[curr].size())
        {
            string last = mp[curr][mp[curr].size()-1];
            mp[curr].pop_back();
            dfs(last);
        }
        ans.push_back(curr);
    }
};

// SImple topological sort intutuion.
