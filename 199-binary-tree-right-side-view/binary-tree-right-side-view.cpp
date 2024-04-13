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
    void traversal(TreeNode* root,int lvl,unordered_map<int,int> &ans){
        if(root == NULL){
            return;
        }
        traversal(root->left,lvl+1,ans);
        ans[lvl] = root->val;
        traversal(root->right,lvl+1,ans);
    }
    vector<int> rightSideView(TreeNode* root) {
        int lvl = 0;
        unordered_map<int,int> mp;
        traversal(root,lvl,mp);
        int s = mp.size();
        vector<int> ans(s);
        for(auto i:mp){
            ans[i.first] = i.second;
        }
        return ans;
    }
};