/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(TreeNode* root) {
        if (root == NULL) {
            return NULL;
        }
        TreeNode* leftSide = solve(root->left);
        TreeNode* rightSide = solve(root->right);

        if (leftSide != NULL && rightSide != NULL) {
            root->left = NULL;
            root->right = leftSide;
            TreeNode* curr = root->right;
            while (curr->right != NULL) {
                curr = curr->right;
            }
            curr->right = rightSide;
        } else if (leftSide != NULL && rightSide == NULL) {
            root->left = NULL;
            root->right = leftSide;
        } else if (leftSide == NULL && rightSide != NULL) {
            root->left = NULL;
            root->right = rightSide;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        solve(root);
    }
};