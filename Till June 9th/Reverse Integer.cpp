class Solution {
public:
    bool negative;
    int reverse(int x) {

        int status = handleNegative(x);
        if(status == 0)
            return 0;

        int ans = reversePositive(x);

        if(negative)
            return ans*-1;
        else
            return ans;
    }
    int handleNegative(int &x)
    {
        if(x>=0)
            return 1;

        if((long)x*-1>INT_MAX)
            return 0;

        x*=-1;
        negative = true;
        return 1;
    }
    int reversePositive(int x)
    {
        long ans = 0;
        while(x>0)
        {
            if(ans*10 + x%10 > INT_MAX)
                return 0;
            ans = ans*10 + x%10;
            x/=10;
        }
        return ans;
    }
};
