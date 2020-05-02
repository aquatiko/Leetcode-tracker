// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        long start = 0, end = n;

        while(start<=end)
        {
            long middle = (start+end)/2;

            bool middleVal = isBadVersion(middle);
            bool leftVal = middle-1>=0 ? isBadVersion(middle-1) : 0;

            if(middleVal && (!leftVal))
                return middle;
            else if(!middleVal)
                start = middle+1;
            else
                end = middle-1;
        }
        return start;
    }
};
