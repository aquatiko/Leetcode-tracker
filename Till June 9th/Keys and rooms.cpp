class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);

        dfs(rooms, visited, 0);

        for(int i=0;i<rooms.size();i++)
            if(!visited[i])
                return false;

        return true;
    }
    void dfs(vector<vector<int>> &rooms, vector<bool> &visited, int pos)
    {
        if(visited[pos])
            return;

        visited[pos] = true;

        for(int i=0;i<rooms[pos].size();i++)
        {
            if(!visited[rooms[pos][i]])
                dfs(rooms, visited, rooms[pos][i]);
        }
    }
};
