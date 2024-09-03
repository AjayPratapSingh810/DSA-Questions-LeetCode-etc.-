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
    Node* first(Node* root){
        if(root == NULL){
            return NULL;
        }
        if(root ->left == NULL && root->right == NULL){
            return root;
        }
        Node* left = connect(root->left);
        Node* right = connect(root->right);
        if(left && right){
            left->next = right;
        }
        return root;
    }
    void second(Node* left,Node* right){
        if(left == NULL && right == NULL){
            return;
        }
        if(left == NULL || right == NULL){
            return;
        }
        left -> next = right;
        second(left->right,right->left);
        return;
    }
    Node* connect(Node* root) {
        root = first(root);
        if(root && root->left && root->right){
            second(root->left,root->right);
        }
        return root;
    }
};