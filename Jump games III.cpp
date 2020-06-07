class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> visited(arr.size(), false);

        return dfs(arr, visited, start);
    }
    bool dfs(vector<int> &arr, vector<bool> &visited, int pos)
    {
        if(pos<0 || pos>=arr.size() || visited[pos])
            return false;
        if(arr[pos] == 0)
            return true;

        visited[pos] = true;

        return dfs(arr, visited, pos+arr[pos]) | dfs(arr, visited, pos-arr[pos]);
    }
};
