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
    TreeNode* solve(TreeNode* root,int &sum){
        if(root == NULL){
            return NULL;
        }
        if(root -> left == NULL && root->right == NULL){
            sum = sum + root->val;
            TreeNode* temp = new TreeNode(sum);
            return temp;
        }
        TreeNode* temp  = new TreeNode(root->val);
        temp -> right = solve(root->right,sum);
        sum = sum+root->val;
        temp->val = sum;
        temp-> left = solve(root->left,sum);
        return temp;
    }
    TreeNode* convertBST(TreeNode* root) {
        int sum = 0;
        return solve(root,sum);
    }
};