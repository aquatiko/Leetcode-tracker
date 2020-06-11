class Solution {
public:
    bool isNeg;
    bool isPalindrome(int x) {
        if(x == INT_MIN || x == INT_MAX || x<0)
            return false;

        int revNum = 0;
        int num = x;

        while(num>0)
        {
            revNum = revNum*10 + num%10;
            num/=10;
        }

        return x == revNum;
    }
};
