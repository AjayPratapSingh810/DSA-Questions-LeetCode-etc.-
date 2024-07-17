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
    TreeNode* solve(int s,int e,TreeNode* &root,vector<int> nums){
        if(s>e){
            return NULL;
        }
       int mid = (s+e+1)/2;
       root = new TreeNode(nums[mid]);
       root->left = solve(s,mid-1,root->left,nums);
       root->right = solve(mid+1,e,root->right,nums);
       return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* ans = NULL;
        int start = 0;
        int end = nums.size()-1;
        solve(start,end,ans,nums);
        return ans;
    }
};