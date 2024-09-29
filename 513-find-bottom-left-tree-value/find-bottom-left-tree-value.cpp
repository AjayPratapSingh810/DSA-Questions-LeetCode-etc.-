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
    void solve(TreeNode* root,vector<pair<int,int>> &track,int lvl){
        if(root == NULL){
            return;
        }
        solve(root->left,track,lvl+1);
        track.push_back(make_pair(root->val,lvl));
        solve(root->right,track,lvl+1);
    }
    int findBottomLeftValue(TreeNode* root) {
        vector<pair<int,int>> track;
        solve(root,track,0);
        int maxi = INT_MIN;
        int ans = -1;

        for(int i=0;i<track.size();i++){
            pair<int,int> p = track[i];
            if(p.second > maxi){
                maxi = p.second;
                ans = p.first;
            }
        }
        return ans;
    }
};