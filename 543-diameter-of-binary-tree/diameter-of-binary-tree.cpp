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
    int solve(TreeNode* root,int count,int &ans){
        if(root == NULL){
            return 0;
        }

        int left = solve(root->left,count,ans);
        int right = solve(root->right,count,ans);

        count = left+right;
        if(count > ans){
            ans = count;
        }
        return max(left,right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        solve(root,0,ans);
        return ans;
    }
};