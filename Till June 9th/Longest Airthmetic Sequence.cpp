class Solution {
public:
    int longestArithSeqLength(vector<int>& arr) {
        vector<unordered_map<int,int>> mp(arr.size());
        int ans = 0;
        for(int i=1;i<arr.size();i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                int cd = arr[i] - arr[j];
                if(mp[j].find(cd) == mp[j].end() && mp[i].find(cd) == mp[i].end())
                    mp[i][cd] = 1;
                if(mp[j].find(cd) == mp[j].end() && mp[i].find(cd) != mp[i].end())
                    mp[i][cd] = mp[i][cd];
                else if(mp[j].find(cd) != mp[j].end() && mp[i].find(cd) == mp[i].end())
                    mp[i][cd] = mp[j][cd] + 1;
                else
                    mp[i][cd] = max(mp[j][cd]+1, mp[i][cd]);

                ans = max(ans, mp[i][cd]);
                //cout<<j<<" "<<i<<" "<<ans<<"\t";
            }
        }
        return ans+1;
    }
};

// Elegant solution based on LIS. The 3 different ways to solve LIS is very important to undersatnt conceptualy to be able to
// solve this effortlessly.
