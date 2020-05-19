class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int events[1001]={};
        for(int i=0;i<trips.size();i++)
        {
                events[trips[i][1]]+=trips[i][0];
                events[trips[i][2]]-=trips[i][0];
        }

        int current = 0;
        for(int i=0;i<=1000;i++)
        {
            current+=events[i];
            if(current>capacity)
                return false;
        }
        return true;

    }
};

// Solved this using O(n^2), O(nlongn) (Activity Selection Style) and O(n) (Adhoc)
