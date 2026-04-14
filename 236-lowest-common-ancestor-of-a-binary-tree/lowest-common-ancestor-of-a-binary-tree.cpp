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
    bool solve(TreeNode* &root,TreeNode* p, vector<TreeNode*> &arr){
        if(root == NULL){
            return false;
        }
        if(root-> val == p->val){
            arr.push_back(root);
            return true;
        }
        bool left = solve(root->left,p,arr);
        bool right = solve(root->right,p,arr);
        if(left || right){
            arr.push_back(root);
        }
        return left || right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> arr1;
        vector<TreeNode*> arr2;
        solve(root,p,arr1);
        solve(root,q,arr2);
        unordered_map<int,bool> mp;
        for(int i = 0;i<arr1.size();i++){
            mp[arr1[i]->val] = true;
        }
        TreeNode* ans = NULL;
        for(int i = 0;i<arr2.size();i++){
            if(mp[arr2[i]->val]){
                ans = arr2[i];
                break;
            }
        }
        return ans;
    }
};