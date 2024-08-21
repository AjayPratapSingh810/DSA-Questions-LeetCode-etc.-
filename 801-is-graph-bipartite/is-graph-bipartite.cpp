class Solution {
public:
    bool solveBfs(int i,vector<vector<int> > &graph,vector<int> &colors){
        queue<int> q;
        q.push(i);
        colors[i] = 0;

        while(!q.empty()){
            int top = q.front();
            q.pop();
            for(auto x : graph[top]){
                if(colors[x] == colors[top]){
                    return true;
                }
                if(colors[top] == 0 && colors[x] == -1){
                    colors[x] = 1;
                    q.push(x);
                }else if(colors[top] == 1 && colors[x] == -1){
                    colors[x] = 0;
                    q.push(x);
                }
            }

        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int nodes = graph.size();
        vector<int> colors(nodes,-1);

        for(int i=0;i<nodes;i++){
            if(colors[i] == -1){
                bool ans = solveBfs(i,graph,colors);
                if(ans){
                    return false;
                }
            }
        }
        return true;
    }
};