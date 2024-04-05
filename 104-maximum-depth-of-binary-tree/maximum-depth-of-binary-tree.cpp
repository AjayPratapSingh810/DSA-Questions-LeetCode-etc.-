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
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int leftHeight = solve(root->left);
        int rightHeight = solve(root->right);

        int height = max(leftHeight,rightHeight)+1;
        return height;
    }
    int maxDepth(TreeNode* root) {
        return solve(root);
    }
};