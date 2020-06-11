static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    int minSwap(vector<int>& a, vector<int>& b) {
        int swapped = 1;
        int nswapped = 0;

        for(int i=1;i<a.size();i++)
        {
            bool choice1 = a[i]>a[i-1] && b[i]>b[i-1]; // IS
            bool choice2 = a[i]>b[i-1] && b[i]>a[i-1]; // cross IS

            int new_nswapped = min(choice1? nswapped : INT_MAX, choice2 ? swapped : INT_MAX);
            int new_swapped = min(choice2? nswapped+1 : INT_MAX, choice1 ? swapped+1 : INT_MAX);
            nswapped = new_nswapped;
            swapped = new_swapped;
            //cout<<nswapped<<" "<<swapped<<"\t";
        }
        return min(nswapped, swapped);
    }
};

// Easy 1/0 knapsack based
