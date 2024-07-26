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
    void solve(TreeNode* root,string track,vector<string> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            string a = to_string(root->val);
            track = track+a;
            ans.push_back(track);
            track.pop_back();
            return; 
        }
        string a = to_string(root->val);
        track = track+a;
        track.push_back('-');
        track.push_back('>');
        solve(root->left,track,ans);
        solve(root->right,track,ans);
        while(track[track.length()-1] != '-'){
            track.pop_back();
        }
        track.pop_back();
        track.pop_back();
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string track = "";
        solve(root,track,ans);
        return ans;
    }
};