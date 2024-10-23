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
class Solution {
public:
    TreeNode* solve(TreeNode* &root){
        if(root == NULL){
            return NULL;
        }

        TreeNode* l = solve(root->left);
        TreeNode* r = solve(root->right);

        if(l != NULL && r != NULL){
            TreeNode* i = r;
            root->right = l;
            root->left = NULL;
            TreeNode* x = root->right;
            while(x->right != NULL){
                x = x->right;
            }
            x->right = i;
        }else if(l != NULL && r == NULL){
            root -> right = l;
            root->left = NULL;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        root = solve(root);
    }
};