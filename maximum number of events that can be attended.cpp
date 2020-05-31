class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        if(events.size()==0)
            return 0;
        sort(events.begin(), events.end());


        priority_queue<int, vector<int>, greater<int>> q;

        q.push(events[0][1]);
        int counter = 1;
        int day = events[0][0];
        int ans = 0;
        while(q.size())
        {
            while(counter<events.size() && events[counter][0]<=day && events[counter][1]>=day)
            {
                q.push(events[counter][1]);
                counter++;
            }
            //day = min(day+1,q.top());
            day++;
            ans++;
            q.pop();
            while(q.size() && q.top()<day)
                q.pop();

            if(q.size() == 0 && counter<events.size())
            {
                day = events[counter][0];
                q.push(events[counter][1]);
                counter++;
            }

        }
        return ans;
    }
};
