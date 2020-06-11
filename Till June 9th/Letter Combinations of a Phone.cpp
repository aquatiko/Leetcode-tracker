class Solution {
public:
    vector<string> ans;
    vector<vector<string>> letters;
    vector<string> letterCombinations(string digits) {
        if(digits == "")
            return {};

        letters.push_back({"a","b","c"});
        letters.push_back({"d","e","f"});
        letters.push_back({"g","h","i"});
        letters.push_back({"j","k","l"});
        letters.push_back({"m","n","o"});
        letters.push_back({"p","q","r","s"});
        letters.push_back({"t","u","v"});
        letters.push_back({"w","x","y","z"});

        solve(digits,0,"");

        return ans;
    }

    void solve(string digits, int pos, string combination)
    {
        if(pos == digits.length())
        {ans.push_back(combination); return;}

        for(int i = 0; i<letters[digits[pos] - '2'].size(); i++)
            solve(digits, pos+1, combination + letters[digits[pos] - '2'][i]);
    }
};

// Interesting problem. Can be solved easily with a messy implementation. But writing a lean backtracking code was the challenge here.
