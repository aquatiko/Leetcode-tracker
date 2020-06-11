class Solution {
public:
    int smallestRangeII(vector<int>& a, int k) {
        if(a.size()<2)
            return 0;
        sort(a.begin(),a.end());
        if(k==0)
            return a[a.size()-1]-a[0];
        int ans = a[a.size()-1]-a[0];
        for(int i=0;i+1<a.size();i++)
        {
            int range1low = a[0]+k;
            int range1high = a[i]+k;
            int range2low = a[i+1]-k;
            int range2high = a[a.size()-1]-k;

            ans = min(ans, max(range1high,range2high) - min(range1low, range2low));
        }
        return ans;
    }
};
