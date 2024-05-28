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
    void solve(TreeNode* root,TreeNode* &ans){
        if(root == NULL){
            ans = NULL;
            return;
        }
        TreeNode* temp = new TreeNode(root->val);
        ans = temp;
        solve(root->right,ans->left);
        solve(root->left,ans->right);
    }
    TreeNode* invertTree(TreeNode* root) {
        TreeNode* ans = NULL;
        solve(root,ans);
        return ans;
    }
};