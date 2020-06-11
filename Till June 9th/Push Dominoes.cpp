static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    string pushDominoes(string dominoes) {
        vector<int> rtime(dominoes.length(),INT_MAX);
        int counter = -1;
        for(int i=0;i<dominoes.length();i++)
        {
            if(dominoes[i]=='R')
                counter = 0;
            else if(dominoes[i] == 'L')
                counter = -1;
            else
            {
                if(counter>=0)
                    rtime[i] = (++counter);
            }
        }
        counter = -1;
        for(int i=dominoes.size()-1;i>=0;i--)
        {
            if(dominoes[i]=='L')
                counter = 0;
            else if(dominoes[i]=='R')
                counter = -1;
            else
            {
                if(counter>=0)
                    counter++;

                if(rtime[i]!=INT_MAX && counter<rtime[i] && counter>0)
                    dominoes[i] = 'L';
                else if(rtime[i]==INT_MAX && counter>0)
                    dominoes[i] = 'L';
                else if(counter>0 && counter>rtime[i])
                    dominoes[i] = 'R';
                else if(counter <1 && rtime[i]!=INT_MAX)
                    dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};

// Most optimized version above, another alternative which I coded first is below



static const int fastio = []() {
	#define endl '\n'
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	return 0;
}();
class Solution {
public:
    string pushDominoes(string dominoes) {
        if(dominoes.length()<2)
            return dominoes;
        string ans = dominoes;
        bool flag = true;
        for(int time = 1;flag == true;time++)
        {   flag = false;
            for(int i=0;ans[i]!=NULL;i++)
            {
                if(ans[i] == '.')
                {
                    bool leftPressure = i-1>=0 && ans[i-1] == 'R' ? true : false;
                    bool rightPressure = i+1<ans.length() && ans[i+1] == 'L' ? true : false;

                    if(leftPressure && !rightPressure)
                    {ans[i] = 'r'; flag = true;}
                    else if(!leftPressure && rightPressure)
                    {ans[i] = 'l'; flag = true;}

                }
                if(i-1>=0 && ans[i-1] == 'l')
                    ans[i-1] = 'L';
                else if(i-1>=0 && ans[i-1] == 'r')
                    ans[i-1] = 'R';
            }
            if(ans[ans.length()-1] == 'r')
                ans[ans.length()-1] = 'R';
            if(ans[ans.length()-1] == 'l')
                ans[ans.length()-1] = 'L';
        }
        return ans;
    }
};
