static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int maxTurbulenceSize(vector<int>& a) {
        if(a.size()==1)
            return 1;
        // flag as true means < comparision and vise versa.
        int best_ans = 1;
        bool flag = a[0]>a[1] ? false : true;
        int ans = 1;
        for(int i=1;i<a.size();i++)
        {
            if(flag == false)
            {
                if(a[i-1]>a[i])
                {ans++; flag = true;}
                else if(a[i-1]<a[i])
                {
                    flag = false;
                    ans = 2;
                }
                else
                {
                    if(i+1>=a.size())
                        break;
                    flag = a[i]>a[i+1]?false:true;
                    ans=1;
                }
            }
            else
            {
                if(a[i-1]<a[i])
                {ans++; flag = false;}
                else if(a[i-1]>a[i])
                {
                    flag = true;
                    ans = 2;
                }
                else
                {
                    if(i+1>=a.size())
                        break;
                    flag = a[i]>a[i+1]?false:true;
                    ans=1;
                }
            }
            best_ans = max(ans, best_ans);
        }
        return best_ans;
    }
};

// its just finding the longest sequence of peaks and vallies in a subarray.
// Overly complicated problem statement with incorrect D.P tag, no d.p was needed though.
