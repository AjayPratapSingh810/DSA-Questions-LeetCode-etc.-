class Solution {
public:
    void solve(vector<vector<int>>& rooms,vector<bool> &visited){
        queue<int> q;
        q.push(0);
        visited[0] = true;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(int i=0;i<rooms[top].size();i++){
                int x = rooms[top][i];
                if(!visited[x]){
                    visited[x] = true;
                    q.push(x);
                }
            }

        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int s = rooms.size();
        vector<bool> visited(s,false);
        solve(rooms,visited);
        for(int i=0;i<s;i++){
            if(visited[i] == false){
                return false;
            }
        }
        return true;
    }
};