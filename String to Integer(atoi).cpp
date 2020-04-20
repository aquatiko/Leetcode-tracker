class Solution {
public:
    bool isNeg;
    long ans;
    int myAtoi(string str) {
        trimLeadingSpaces(str);

        handleSign(str);

        convertPositive(str);

        if(ans == INT_MIN || !isNeg)
            return ans;
        else
            return -1*ans;

    }
    void trimLeadingSpaces(string &str)
    {
        int startPos = 0;
        while(str[startPos]==' ')
            startPos++;

        str = str.substr(startPos);
    }
    void handleSign(string &str)
    {   isNeg = false;
        if(str[0] == '-')
            isNeg = true;
        if(str[0] == '+' || str[0] == '-')
            str = str.substr(1);
    }
    void convertPositive(string s)
    {   ans = 0;
        for(int i=0;s[i]!=NULL;i++)
        {
            if(s[i]>='0' && s[i]<='9')
            {
                ans= ans*10 + (s[i] - '0');
            }
            else
                break;

            if(isNeg && ans*-1 < INT_MIN)
            {
                ans = INT_MIN;
                break;
            }
            if(!isNeg && ans>INT_MAX)
            {
                ans = INT_MAX;
                break;
            }
        }
    }
};

// Modularity is helping in creating less bugs and perfect edge case coverage. But need to improve speed with this.
