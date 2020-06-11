class Solution {
public:
    string ans;
    string convert(string s, int numRows) {
        outsideLine(s,0,numRows);

        for(int i=0;i<numRows-2;i++)
            insideLine(s,i+1,numRows);

        if(numRows>1)
        outsideLine(s,numRows-1,numRows);

        return ans;
    }

    void outsideLine(string s,int startPos, int numRows)
    {
        for(int i=startPos;i<s.length();i+= max(2*(numRows-1),1))
            ans+=s[i];
    }

    void insideLine(string s,int startPos, int numRows)
    {
        for(int i=startPos;i<s.length();i+= max(2*(numRows-1),1))
        {
            ans+=s[i];
            if(i + 2*(numRows - 1 - startPos) <s.length())
                ans+= s[i + 2*(numRows - 1 - startPos)];
        }
    }
};
