class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int> > adjList;
        vector<int> inDegree(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            inDegree[u]++;
            adjList[v].push_back(u);
        }
        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int count = 0;
        vector<int> arr;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            count++;
            arr.push_back(top);
            for(int i = 0;i<adjList[top].size();i++){
                inDegree[adjList[top][i]]--;
                if(inDegree[adjList[top][i]] == 0){
                    q.push(adjList[top][i]);
                }
            }
        }
        if(count == numCourses){
            return arr;
        }
        vector<int> ans;
        return ans;
    }
};