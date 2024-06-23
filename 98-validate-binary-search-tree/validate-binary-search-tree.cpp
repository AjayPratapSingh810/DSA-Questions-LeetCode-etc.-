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
    void solve(TreeNode* root,vector<int> &arr){
        if(root == NULL){
            return;
        }
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
    }
    bool isValidBST(TreeNode* root) {
        vector<int> inorder;
        solve(root,inorder);

        for(int i = 0;i<inorder.size()-1;i++){
            if(inorder[i] >= inorder[i+1]){
                return false;
            }
        }
        return true;
    }
};