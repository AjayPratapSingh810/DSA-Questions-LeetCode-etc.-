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
    void solve(TreeNode* root,int target,int &sum,vector<vector<int> > &ans,vector<int> &arr){
        if(root == NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL && sum+root->val == target){
            arr.push_back(root->val);
            ans.push_back(arr);
            arr.pop_back();
        }
        arr.push_back(root->val);
        sum = sum+root->val;
        solve(root->left,target,sum,ans,arr);
        solve(root->right,target,sum,ans,arr);
        sum = sum-root->val;
        arr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int> > ans;
        vector<int> arr;
        int sum = 0;
        solve(root,targetSum,sum,ans,arr);
        return ans;
    }
};