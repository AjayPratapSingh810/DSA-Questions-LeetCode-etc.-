class Solution {
public:
    // bool solveDfs(int x,vector<vector<int> >& graph,vector<bool> &cycle,vector<bool> &visited,vector<bool> &pathVisited){
    //     visited[x] = true;
    //     pathVisited[x] = true;
    //     vector<int> vec = graph[x];
    //     for(int i=0;i<vec.size();i++){
    //         if(visited[vec[i]] && pathVisited[vec[i]]){
    //             cycle[vec[i]] = true;
    //             return true;
    //         }
    //         if(!visited[vec[i]]){
    //              bool ans = solveDfs(vec[i],graph,cycle,visited,pathVisited);
    //         if(ans){
    //             cycle[vec[i]] = true;
    //             return true;
    //         }
    //         }
           
    //     }
    //     pathVisited[x] = false;
    //     return false;
    // }
    void solveBfs(vector<vector<int> >& graph,vector<int> &ans){
        vector<vector<int> > adjList(graph.size());
        vector<int> inDegree(graph.size());
        for(int i=0;i<graph.size();i++){
            for(int j = 0;j<graph[i].size();j++){
                adjList[graph[i][j]].push_back(i);
                inDegree[i]++;
            }
        }

        queue<int>q;
        for(int i=0;i<inDegree.size();i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans.push_back(top);
            for(int i=0;i<adjList[top].size();i++){
                inDegree[adjList[top][i]]--;
                if(inDegree[adjList[top][i]] == 0){{
                    q.push(adjList[top][i]);
                }}
            }
        }
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // -----------DFS--------------
        // int size = graph.size();
        // vector<bool> cycle(size,false);
        // vector<bool> pathVisited(size,false);
        // vector<bool> visited(size,false);
        // for(int i=0;i<size;i++){
        //     if(cycle[i] == false){
        //         bool ans = solveBfs(i,graph,cycle,visited);
        //         if(ans){
        //             cycle[i] = true;
        //         }
        //     }
        // }
        // vector<int> ans;
        // for(int i=0;i<size;i++){
        //     if(cycle[i] == false){
        //         ans.push_back(i);
        //     }
        // }
        // return ans;

        vector<int> ans;
        solveBfs(graph,ans);
        sort(ans.begin(),ans.end());
        return ans;
    }
};