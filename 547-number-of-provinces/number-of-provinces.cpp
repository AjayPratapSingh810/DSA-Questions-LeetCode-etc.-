class Solution {
public:
    void solve(vector<vector<int>>& isConnected,vector<int> &visited,int s){
        queue<int> q;
        q.push(s);
        visited[s] = 1;

        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(int i=0;i<isConnected[top-1].size();i++){
                if(isConnected[top-1][i] == 1 && visited[i+1] == -1){
                    visited[i+1] = 1;
                    q.push(i+1);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        // in this we do bfs
        int size = isConnected.size(); 
        vector<int> visited(size+1,-1);
        int ans = 0;
        for(int i = 1;i<=size;i++){
            if(visited[i] == -1){
                ans++;
                solve(isConnected,visited,i);
            }
        }
        return ans;
    }
};