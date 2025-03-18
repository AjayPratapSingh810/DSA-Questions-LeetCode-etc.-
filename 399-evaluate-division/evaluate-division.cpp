class Solution {
public:
    double
    solveDfs(unordered_map<string, vector<pair<string, double>>>& adjList,
             string src, string dest,unordered_set<string>& visited) {
        if (src == dest) {
            return 1.0;
        }
        if (visited.count(src)) return -1.0;
        visited.insert(src);
        for (int i = 0; i < adjList[src].size(); i++) {
            double a = solveDfs(adjList, adjList[src][i].first, dest,visited);
            if (a > 0) {
                return a * adjList[src][i].second;
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations,
                                vector<double>& values,
                                vector<vector<string>>& queries) {
        unordered_map<string, vector<pair<string, double>>> adjList;
        for (int i = 0; i < equations.size(); i++) {
            adjList[equations[i][0]].push_back(
                make_pair(equations[i][1], values[i]));
            adjList[equations[i][1]].push_back(
                make_pair(equations[i][0], 1.0 / values[i]));
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            if (adjList.find(queries[i][0]) == adjList.end() ||
                adjList.find(queries[i][1]) == adjList.end()) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string> visited;
            ans.push_back(solveDfs(adjList, queries[i][0], queries[i][1],visited));
        }
        return ans;
    }
};