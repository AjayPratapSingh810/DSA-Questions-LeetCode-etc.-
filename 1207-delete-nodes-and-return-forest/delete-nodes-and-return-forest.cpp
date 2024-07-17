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
    TreeNode* solve(TreeNode* root,unordered_set<int> &to_delete_set,vector<TreeNode*>& ans){
        if(root == NULL){
            return NULL;
        }
        root->left = solve(root->left,to_delete_set,ans);
        root->right = solve(root->right,to_delete_set,ans);

        if(to_delete_set.count(root->val)){
            if(root->left){
                ans.push_back(root->left);
            }
            if(root->right){
                ans.push_back(root->right);
            }
            return NULL;
        }
        return root;
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> to_delete_set(to_delete.begin(), to_delete.end());
        vector<TreeNode*> ans;
        if(solve(root,to_delete_set,ans)){
            ans.push_back(root);
        }
        return ans;
    }
};