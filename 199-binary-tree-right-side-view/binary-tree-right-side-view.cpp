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
    void solve(int lvl,TreeNode* root,vector<int> &mp){
        if(root == NULL){
            return;
        }
        solve(lvl+1,root->left,mp);
        mp[lvl]=root->val;
        solve(lvl+1,root->right,mp);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> mp(100,INT_MAX);
        solve(0,root,mp);
        vector<int> ans;
        for(auto i:mp){
            if(i != INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};