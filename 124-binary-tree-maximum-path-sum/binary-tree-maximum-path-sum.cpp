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
    int solve(TreeNode* root,int &sum){
        if(root == NULL){
            return 0;
        }
        int l = solve(root->left,sum);
        int r  = solve(root->right,sum);
        int add = max(root->val, max(l+root->val,max(r+root->val,l+r+root->val)));
        if(sum < add){
            sum = add;
        } 
        if(root->val > l+root->val && root->val >  r+root->val){
            return root->val;
        }
        else if(l+root->val > r+root->val){
            return l+root->val;
        }
        return r+root->val;

    }
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN;
        solve(root,sum);
        return sum;
    }
};