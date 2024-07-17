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
    TreeNode* solve(TreeNode* &root,vector<int> to_delete,vector<TreeNode*> &ans){
        if(root == NULL){
            return NULL;
        }
        TreeNode* leftSide = solve(root->left,to_delete,ans);
        TreeNode* rightSide = solve(root->right,to_delete,ans);
        for(int i=0;i<to_delete.size();i++){
            if(to_delete[i] == root->val){
                if(leftSide == NULL && rightSide== NULL){
                    return NULL;
                }
                else{
                    if(leftSide){
                        ans.push_back(root->left);
                    }
                    if(rightSide){
                        ans.push_back(root->right);
                    }
                    return NULL;
                }
            }
        }
        if(leftSide == NULL){
            root->left = NULL;
        }
        
        if(rightSide == NULL){
            root->right = NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        solve(root,to_delete,ans);
        bool involveRoot = true;
        for(int i=0;i<to_delete.size();i++){
            if(to_delete[i] == root->val){
                involveRoot = false;
            }
        }
        if(involveRoot){
            ans.push_back(root);
        }
        return ans;
    }
};