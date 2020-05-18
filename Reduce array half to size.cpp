class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int i=0;i<arr.size();i++)
        {
            mp[arr[i]]++;
        }
        int n = arr.size();
        priority_queue<int> q;
        for(auto itr:mp)
            q.push(itr.second);

        int ans = 0;
        while(q.size() && n>arr.size()/2)
        {
            n-=q.top();
            q.pop();
            ans++;
        }
        return ans;
    }
};
