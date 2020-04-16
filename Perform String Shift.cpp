class Solution {
public:
    string stringShift(string s, vector<vector<int>>& shift) {
        int netShift = 0;  // negative means left shifts
        string ans;

        for(int i=0;i<shift.size();i++)
        {
            if(shift[i][0] == 0)
                netShift -= shift[i][1];
            else
                netShift += shift[i][1];
        }
        if(netShift>0)
        netShift %= s.length();
        else
        {
            netShift*=-1;
            netShift %= s.length();
            netShift*=-1;
        }

        if(netShift == 0)
            return s;
        else if(netShift <0)
        {
            ans += s.substr(abs(netShift));
            ans += s.substr(0, abs(netShift));
        }
        else
        {
            ans += s.substr(s.length() - netShift);
            ans += s.substr(0, s.length() - netShift);
        }

        return ans;

    }
};

// AC on 2nd try. Created a bug by using mod in case of negative mods. Case added to handle those gave AC.
