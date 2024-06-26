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
    void solve(TreeNode* root,vector<int> &arr){
        if(root == NULL){
            return;
        }
        solve(root->left,arr);
        arr.push_back(root->val);
        solve(root->right,arr);
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int> arr;
        solve(root,arr);
        sort(arr.begin(),arr.end());
        int ans = INT_MAX;
        for(int i = 0;i<arr.size()-1;i++){
            int diff = arr[i+1]-arr[i];
            if(ans > diff){
                ans = diff;
            }
        }
        return ans;
    }
};