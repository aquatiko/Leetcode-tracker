int mod(string num, int m)
{
    // Store the modulus of big number
    int mod = 0;

    // Do step by step division
    for (int i = 0; i < num.size(); i++) {

        int digit = num[i] - '0';

        // Update modulo by concatenating
        // current digit.
        mod = mod * 10 + digit;

        // Update quotient
        int quo = mod / m;

        // Update mod for next iteration.
        mod = mod % m;
    }

    return mod;
}
bool check(string s)
{   //cout<<s<<" ";
    for(int i=0;s[i]!=NULL;i++)
        if(!(s[i]=='1' || s[i]=='0'))
            return false;
    return true;
}
string Solution::multiple(int n) {
    queue<string> q;
    q.push("1");
    while(q.size())
    {
        string top = q.front();
        q.pop();
        if(mod(top,n) == 0)
            return top;
        q.push(top + "0");
        q.push(top + "1");
    }
    return "";
}

// BFS is used in calculating next potential answer.
