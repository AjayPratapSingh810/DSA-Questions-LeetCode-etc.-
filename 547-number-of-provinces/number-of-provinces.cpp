class Solution {
public:
    void solve(int x,vector<vector<int> > &adjList,vector<bool> &visited){
        queue<int> q;
        q.push(x);
        visited[x] = true;
        while(!q.empty()){
            int top = q.front();
            q.pop();

            for(int i = 0;i<adjList[top].size();i++){
                if(!visited[adjList[top][i]]){
                    visited[adjList[top][i]] = true;
                    q.push(adjList[top][i]);
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int> > adjList(n);
        for(int i =0 ;i<isConnected.size();i++){
            for(int j = 0;j<isConnected[i].size();j++){
                if(i == j){
                    continue;
                }
                if(isConnected[i][j] == 1){
                    adjList[i].push_back(j);
                }
            }
        }

        vector<bool> visited(isConnected.size(),false);
        int ans = 0;
        for(int i = 0;i<isConnected.size();i++){
            if(visited[i] == false){
                ans++;
                solve(i,adjList,visited);
            }
        }
        return ans;

    }
};