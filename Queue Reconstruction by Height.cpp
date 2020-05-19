class Solution {
public:
    static bool compare(vector<int> &a, vector<int> &b)
    {
        if(a[0]==b[0])
            return a[1]>b[1];
        return a[0]<b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(),people.end(),compare);

        for(int i=people.size()-1;i>=0;i--)
        {
            int swaps = people[i][1];
            for(int j=0;j<swaps;j++)
            {
                swap(people[i+j],people[i+j+1]);
            }
        }
        return people;
    }
};


// intution: Sort the array based on their height in ascending order. Now from the back of the array, each of the person is
// complaning that I need this many people of greater (or equal) height ahead me, no worries, he just needs to move a lil bit
// backwards (swapping here) to fulfill his criteria. Also, greedy comes to picture here as solving like this way gives
// optimum solution for the ones we already fulfilled. (Note moving of any smaller pieces will not trouble a person).

// to handle the equal height case, a comparator was used to go with the designed algo.
