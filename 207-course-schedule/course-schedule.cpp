class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> mp;
        vector<int> inDegree(numCourses,0);
        for(int i = 0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            inDegree[u]++;
            mp[v].push_back(u);
        }

        queue<int> q;
        for(int i = 0;i<numCourses;i++){
            if(inDegree[i] == 0){
                q.push(i);
            }
        }
        int ans=0;
        while(!q.empty()){
            int top = q.front();
            q.pop();
            ans++;
            for(int i = 0;i<mp[top].size();i++){
                inDegree[mp[top][i]]--;
                if(inDegree[mp[top][i]] == 0){
                    q.push(mp[top][i]);
                }
            }
        }
        return ans == numCourses;
    }
};