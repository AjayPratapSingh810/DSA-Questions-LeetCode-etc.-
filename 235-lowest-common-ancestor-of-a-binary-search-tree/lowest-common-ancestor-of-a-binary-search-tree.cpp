/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    void solve(TreeNode* root,TreeNode* p,TreeNode* &ans,unordered_map<int,bool> &mp){
        if(root == NULL){
            return;
        }
        if(mp[root->val]){
            ans = root;
        }
        if(root->val == p->val){
            mp[root->val] = true;
            return;
        }
        mp[root->val] = true;
        if(root->val > p->val){
            solve(root->left,p,ans,mp);
        }
        if(root->val < p->val){
            solve(root->right,p,ans,mp);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans;
        unordered_map<int,bool> mp;
        solve(root,p,ans,mp);
        solve(root,q,ans,mp);
        return ans;
    }
};