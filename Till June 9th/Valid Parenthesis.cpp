class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        for(int i=0;s[i]!='\0';i++)
        {
            if(s[i] == '(')
                stk.push(s[i]);
            else if(s[i] == '{')
                stk.push(s[i]);
            else if(s[i] == '[')
                stk.push(s[i]);
            else if(s[i] == ')')
            {
                if(stk.size()>0 && stk.top() == '(')
                    stk.pop();
                else
                    return false;

            }
            else if(s[i] == '}')
            {
                if(stk.size()>0 && stk.top() == '{')
                    stk.pop();
                else
                    return false;
            }
            else
            {
                if(stk.size()>0 && stk.top() == '[')
                    stk.pop();
                else
                    return false;
            }
        }

        if(stk.size()!=0)
            return false;
        return true;

    }
};

// WAs caused due to not reading question carefully.
