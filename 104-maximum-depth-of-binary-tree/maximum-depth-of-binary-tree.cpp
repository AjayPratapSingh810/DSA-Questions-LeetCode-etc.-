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
    void solve(TreeNode* root,int count,int &ans){
        if(root == NULL){
            if(count > ans){
                ans = count;
            }
            return;
        }
            solve(root->left,count+1,ans);
            solve(root->right,count+1,ans);
    }
    int maxDepth(TreeNode* root) {
        int count = 0;
        int ans = 0;
        solve(root,count,ans);
        return ans; 
    }
};