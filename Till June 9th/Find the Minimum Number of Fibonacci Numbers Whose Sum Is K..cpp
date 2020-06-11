class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        int a= 1, b= 1;
        vector<int> fib;
        fib.push_back(1);
        while(b<=k)
        {
            int c = a+b;
            fib.push_back(c);
            a=b;
            b=c;
        }
        int ans = 0;
        while(k>0)
        {
            auto itr = upper_bound(fib.begin(),fib.end(),k);
            itr--;
            ans++;
            k-= (*itr);
        }
        return ans;
    }
};
