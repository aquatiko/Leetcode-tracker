static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        int count[26]={};
        for(int i=0;s[i]!=NULL;i++)
            count[s[i]-'a']++;
        priority_queue<pair<int,char>> q;
        for(int i=0;i<26;i++)
            if(count[i])
                q.push({count[i],i+'a'});

        while(q.size()>=2)
        {
            pair<int,char> t1,t2;
            t1 = q.top();
            q.pop();
            t2 = q.top();
            q.pop();

            ans = ans + (t1.second) + (t2.second);
            if(t1.first-1>0)
            q.push({t1.first-1, t1.second});
            if(t2.first-1>0)
            q.push({t2.first-1, t2.second});
            //cout<<ans<<" ";
        }
        if(q.size()==1 && q.top().first>1)
            return "";
        if(q.size()==1)
        return ans + (q.top().second);

        return ans;
    }
};
