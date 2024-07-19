/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
TreeNode* solve(TreeNode* root,TreeNode* base,TreeNode* target){
        if(root == NULL){
            return NULL;
        }
        if(base == target){
            return root;
        }
        TreeNode* leftSide = solve(root->left,base->left,target);
        TreeNode* rightSide = solve(root->right,base->right,target);

        if(leftSide == NULL){
            return rightSide;
        }
        return leftSide;
}
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return solve(cloned,original,target);
    }
};