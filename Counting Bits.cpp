class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> ans;
        for(int i=0;i<=num;i++)
            ans.push_back(__builtin_popcount(i));
        return ans;
    }
};

// Pattern finding solution was interesting.
// Thinking process: https://leetcode.com/problems/counting-bits/discuss/79557/How-we-handle-this-question-on-interview-Thinking-process-%2B-DP-solution
