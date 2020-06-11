class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int ans =0;
        sort(people.begin(),people.end());
        int ptr1 = 0, ptr2 = people.size()-1;
        while(ptr2>=ptr1)
        {
            if(people[ptr2]+people[ptr1]<=limit)
            {ptr2--;ptr1++;}
            else
                ptr2--;

            ans++;
        }
        return ans;
    }
};
