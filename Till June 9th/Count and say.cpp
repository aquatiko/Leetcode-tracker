class Solution {
public:
    string countAndSay(int n) {
        string ans = "1";

        if(n<2)
            return ans;

        for(int i=2;i<=n;i++)
        {
            int count = 1;
            string tmpAns = "";

            char ch = ans[0];

            for(int j= 1;ans[j]!='\0';j++)
            {
                if(ans[j]!=ch)
                {
                    tmpAns += to_string(count) + ch;
                    ch = ans[j];
                    count=1;
                }
                else
                {
                    count++;
                }
            }
            tmpAns += to_string(count) + ch;
            ans = tmpAns;

        }

        return ans;
    }
};
