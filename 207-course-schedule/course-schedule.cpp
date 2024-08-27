class Solution {
public:
    void solve(int x,vector<vector<int> > &adjList,vector<bool> &visited,stack<int> &st){
        visited[x] = true;

        for(int i = 0;i<adjList[x].size();i++){
            if(!visited[adjList[x][i]]){
                solve(adjList[x][i],adjList,visited,st);
            }
        }

        st.push(x);
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > adjList(numCourses);
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adjList[u].push_back(v);
        }

        vector<bool> visited(numCourses,false);
        stack<int> st;
        for(int i = 0;i<numCourses;i++){
            if(!visited[i]){
                solve(i,adjList,visited,st);
            }
        }
        unordered_map<int,int> mp;
        int s = numCourses-1;
        vector<int> ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        for(int i = 0;i<ans.size();i++){
            mp[ans[i]] = i;
        }
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            if(mp[v] <= mp[u]){
                return false;
            }
        }
        return true;
    }

};