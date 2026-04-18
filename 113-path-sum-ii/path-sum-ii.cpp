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
    void solve(TreeNode* root,int target,vector<int> arr,int sum,vector<vector<int>> &ans){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(sum+root->val == target){
                arr.push_back(root->val);
                ans.push_back(arr);
                arr.pop_back();
            }
            return;
        }
        sum += root->val;
        arr.push_back(root->val);
        solve(root->left,target,arr,sum,ans);
        solve(root->right,target,arr,sum,ans);
        arr.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> arr;
        solve(root,targetSum,arr,0,ans);
        return ans;
    }
};