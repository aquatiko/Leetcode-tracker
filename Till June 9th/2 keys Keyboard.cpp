class Solution {
public:
    int minSteps(int target, int current = 1, int clipboard = 0, int steps = 0) {

        if(current == target)
            return steps;
        if(current>target)
            return INT_MAX;

        return min(clipboard == 0 ? INT_MAX : minSteps(target, current+clipboard, clipboard, steps+1), minSteps(target, current + current, current, steps+2));
    }
};

// See the prime factorization method explanation also.
