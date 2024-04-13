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
    void traverse(TreeNode* root,int lvl, map<int,int> &mp){
        if(root == NULL){
            return;
        }
        traverse(root->left,lvl+1,mp);
        mp[lvl] = mp[lvl]+root->val;
        traverse(root->right,lvl+1,mp);
     }
    int maxLevelSum(TreeNode* root) {
        int lvl = 1;
        map<int,int> mp;
        traverse(root,lvl,mp);
        int ans = 0;
        int maxi =INT_MIN;
        for(auto i:mp){
            if(i.second > maxi){
                maxi = i.second;
                ans = i.first;
            }
        }
        return ans;
    }
};