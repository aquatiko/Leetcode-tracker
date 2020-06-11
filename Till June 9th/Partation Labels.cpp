class Solution {
public:
    vector<int> partitionLabels(string s) {
        if(s.length()==0)
            return {};
        int lastpos[26];
        for(int i=0;s[i]!=NULL;i++)
            lastpos[s[i]-'a']=i;

        int ptr=lastpos[s[0]-'a'];
        vector<int> ans;
        int count = 1;
        for(int i=1;s[i]!=NULL;i++)
        {
            if(ptr<i)
            {
                ans.push_back(count);
                count=0;
            }
            count++;
            ptr = max(ptr,lastpos[s[i]-'a']);
        }
        ans.push_back(count);
        return ans;
    }
};

// I dont understand how magically the intution for this question came to me. I tried to look at it, couldn't get anything.
//solved some problems on Interviewbit, understood what it means to solve greedily. Came to this question from there, looked it
// casually and tried to think greedily for a few minutes and there was the answer before me.
//Really practice makes perfect.
// *smart practice
