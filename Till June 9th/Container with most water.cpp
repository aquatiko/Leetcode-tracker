class Solution {
public:
    int best;
    int maxArea(vector<int>& height) {
        best = 0;
        int ptrfront = 0, ptrback = height.size()-1;

        while(ptrfront<ptrback)
        {
            best = max(best, min(height[ptrfront],height[ptrback]) * (ptrback-ptrfront));

            if(height[ptrfront]<height[ptrback])
                ptrfront++;
            else
                ptrback--;
        }

        return best;
    }
};

// Knew the solution from last time.
