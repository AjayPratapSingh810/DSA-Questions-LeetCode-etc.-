class Solution {
public:
    void bfs(int i,vector<vector<int>>& graph,unordered_map<int,bool> &mp1,unordered_map<int,bool> &mp2,vector<bool> &visited){
        queue<pair<int,int>> q;
        q.push(make_pair(i,0));
        // node,lvl
        visited[i] = true;
        while(!q.empty()){
            pair<int,int> p = q.front();
            q.pop();
            int node = p.first;
            int lvl = p.second;
            if(lvl%2 == 0){
                mp1[node] = true;
            }else{
                mp2[node] = true;
            }

            for(int i = 0;i<graph[node].size();i++){
                if(!visited[graph[node][i]]){
                    visited[graph[node][i]] = true;
                    q.push(make_pair(graph[node][i],lvl+1));
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        unordered_map<int,bool> mp1;
        unordered_map<int,bool> mp2;

        
        int size = graph.size();
        vector<bool> visited(size,false);
        for(int i = 0;i<size;i++){
            if(!visited[i]){
                bfs(i,graph,mp1,mp2,visited);
            }
        }
        for(int i = 0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                if(mp1[i] && mp1[graph[i][j]]){
                    return false;
                }
                if(mp2[i] && mp2[graph[i][j]]){
                    return false;
                }
            }
        }
        return true;
    }
};