/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    void traversal(TreeNode* root,vector<int> &arr){
        if(root == NULL){
            return;
        }
        traversal(root->left,arr);
        arr.push_back(root->val);
        traversal(root->right,arr);
    }
    int start;
    vector<int> arr;
    BSTIterator(TreeNode* root) {
        start = 0;
        TreeNode* curr = root;
        traversal(curr,arr);
    }
    
    int next() {
        return arr[start++];
    }
    
    bool hasNext() {
        if(start < arr.size()){
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */