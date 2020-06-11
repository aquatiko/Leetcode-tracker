class Solution {
public:
    int maximumSum(vector<int>& arr) {
        if(arr.size()==1)
            return arr[0];
        int dropped = max(arr[0],arr[1]);
        int not_dropped = max(arr[0]+arr[1], arr[1]);

        int ans = max(not_dropped, dropped);

        for(int i=2;i<arr.size();i++)
        {
            dropped = max(not_dropped, dropped + arr[i]);
            not_dropped = max(not_dropped + arr[i], arr[i]);
            ans = max(ans, max(dropped, not_dropped));
        }
        return ans;
    }
};

// clever code of O(n) time and O(1) space
// Another interesting solution of O(n) space complexity is to use an extensio nof maximum subarray sum by using the idea that
// whenever we leave one element at index i, it divides the problem into two: maiximum subbaray sum ending at index i-1 + starting at index i+1.
