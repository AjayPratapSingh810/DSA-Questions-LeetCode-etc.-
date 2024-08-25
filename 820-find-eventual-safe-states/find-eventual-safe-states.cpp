class Solution {
public:
    bool solveDfs(int x,vector<vector<int> >& graph,vector<bool> &cycle,vector<bool> &visited,vector<bool> &pathVisited){
        visited[x] = true;
        pathVisited[x] = true;
        vector<int> vec = graph[x];
        for(int i=0;i<vec.size();i++){
            if(visited[vec[i]] && pathVisited[vec[i]]){
                cycle[vec[i]] = true;
                return true;
            }
            if(!visited[vec[i]]){
                 bool ans = solveDfs(vec[i],graph,cycle,visited,pathVisited);
            if(ans){
                cycle[vec[i]] = true;
                return true;
            }
            }
           
        }
        pathVisited[x] = false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size = graph.size();
        vector<bool> cycle(size,false);
                vector<bool> pathVisited(size,false);
        vector<bool> visited(size,false);
        for(int i=0;i<size;i++){
            if(cycle[i] == false){
                bool ans = solveDfs(i,graph,cycle,visited,pathVisited);
                if(ans){
                    cycle[i] = true;
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<size;i++){
            if(cycle[i] == false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};