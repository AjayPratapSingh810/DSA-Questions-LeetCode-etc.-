/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
    private:
    unordered_map<Node*, Node*> visited;
public:
    Node* solveDfs(Node* node){
        if(node == NULL){
            return NULL;
        }
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        Node*temp = new Node(node->val);
        visited[node] = temp;
        for (auto neighbor : node->neighbors) {
            temp->neighbors.push_back(solveDfs(neighbor));
        }
        return temp;
    }
    Node* cloneGraph(Node* node) {
        return solveDfs(node);
    }
};