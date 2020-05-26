class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        string ans = "";
        priority_queue<pair<int,string>> q;
        if(a)
        q.push({a,"a"});
        if(b)
        q.push({b,"b"});
        if(c)
        q.push({c,"c"});
        while(q.size()>=2)
        {
            pair<int,string> t1,t2;
            t1 = q.top();
            q.pop();
            t2 = q.top();
            q.pop();

            if(t1.first>=2 && t1.first-t2.first>=2)
            {
                ans = ans + (t1.second + t1.second);
                t1.first-=2;
                ans = ans + t2.second;
                t2.first-=1;
            }
            else
            {
                ans = ans + (t1.second);
                t1.first-=1;
                ans = ans + t2.second;
                t2.first-=1;
            }
            if(t1.first>0)
                q.push(t1);
            if(t2.first>0)
                q.push(t2);
        }
        if(q.size())
        {
            if(q.top().first >= 2)
                ans = ans + q.top().second + q.top().second;
            else
                ans = ans + q.top().second;
        }
        return ans;
    }
};
