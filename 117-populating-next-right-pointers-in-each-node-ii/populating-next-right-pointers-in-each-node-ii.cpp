/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    void solve(Node* root){
        queue<Node*> q;
        vector<Node*> v;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            Node* top = q.front();
            q.pop();
            if(top != NULL){
                v.push_back(top);
            }
            if(top == NULL){
                if(v.size() > 1){
                    for(int i=0;i<v.size()-1;i++){
                        v[i]->next = v[i+1];
                    }
                }
                v.clear();
                if(q.size() > 0){
                    q.push(NULL);
                }
            }else{
                if(top -> left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }
        }
    }
    Node* connect(Node* root) {
        if(root == NULL){
            return root;
        }
        solve(root);
        return root;
    }
};