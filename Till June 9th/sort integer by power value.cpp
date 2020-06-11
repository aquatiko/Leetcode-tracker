class Solution {
public:
    unordered_map<int,int> poweri;
    int getKth(int lo, int hi, int k) {
        poweri[1] = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> ans;
        for(int i=lo;i<=hi;i++)
        {int res=calculate_power(i);
         ans.push({res,i});
        }

        for(int i=0;i<k-1;i++)
            ans.pop();

        return ans.top().second;
    }

    int calculate_power(int n)
    {
        if(poweri.find(n)!=poweri.end())
            return poweri[n];

        return poweri[n] = n%2==0 ?1 + calculate_power(n/2) :1 + calculate_power(3*n + 1);
    }
};
