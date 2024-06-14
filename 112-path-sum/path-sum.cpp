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
    bool solve(TreeNode* root,int targetSum,int &sum){
        if(root == NULL){
            return false;
        }
        if(root->left == NULL && root->right == NULL){
            if(sum+root->val == targetSum){
                return true;
            }
            return false;
        }
        sum = sum+root->val;
        bool left = solve(root->left,targetSum,sum);
        bool right = solve(root->right,targetSum,sum);

        if(left == true){
            return true;
        }else if(right == true){
            return true;
        }
        sum = sum-root->val;
        return false;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        int sum = 0;
        if(root == NULL){
            return false;
        }
        return solve(root,targetSum,sum);
    }
};