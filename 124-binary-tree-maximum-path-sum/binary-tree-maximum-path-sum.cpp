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
    int solve(TreeNode* root,int &ans){
        if(root == NULL){
            return 0;
        }
        int left = max(0,solve(root->left,ans));
        int right = max(0,solve(root->right,ans));

        int sum = left +right + root->val;
        if(sum > ans){
            ans = sum;
        }
        return max(left,right) + root->val;

    }
    int maxPathSum(TreeNode* root) {
        int sum = 0;
        int ans = INT_MIN;
        int sol = solve(root,ans);
        return max(sol,ans);
    }
};