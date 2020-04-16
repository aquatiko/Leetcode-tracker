class Solution {
public:
    bool checkValidString(string s) {
        stack<int> left, stars;

        for(int i=0;s[i]!=NULL;i++)
        {
            if(s[i]==')' && left.size()==0 && stars.size()==0)
                return false;
            else if(s[i] == ')' && left.size()!=0)
                left.pop();
            else if(s[i] == ')' && left.size()==0)
                stars.pop();
            else if(s[i] == '(')
                left.push(i);
            else
                stars.push(i);
        }

        if(left.size()==0)
            return true;

        while(left.size()>0)
        {
            if(stars.size()==0)
                return false;

            if(left.top() < stars.top())
            {
                left.pop();
                stars.pop();
            }
            else
                return false;
        }
        return true;
    }
};


// AC on 2nd try. Realised after 1st WA that '*' can be substituted with anything but the ordering is important whith whom it is matched. Thus a stack to keep track of indices was required.
