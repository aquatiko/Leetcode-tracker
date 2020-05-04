class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        if(a.size()<3)
            return 0;

        int ans = 0;
        int ptr1 = 0, ptr2 = 2;
        int curr_diff = a[ptr1+1] - a[ptr1];

        while(ptr2<a.size())
        {
            if(a[ptr2]-a[ptr2-1] == curr_diff)
                ans += ptr2-ptr1 - 1;
            else
            {
                ptr1 = ptr2-1;
                curr_diff = a[ptr2] - a[ptr2-1];
            }
            ptr2++;
        }
        return ans;
    }
};
