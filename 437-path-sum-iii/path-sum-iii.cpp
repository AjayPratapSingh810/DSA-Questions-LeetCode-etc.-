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
    void secondSolve(TreeNode* root,long long &sum,int targetSum,int &count){
        if(root == NULL){
            return;
        }
        sum = sum+root->val;
        if(sum == targetSum){
            count++;
        }
        secondSolve(root->left,sum,targetSum,count);
        secondSolve(root->right,sum,targetSum,count);
        sum = sum-root->val;
    }
    void solve(TreeNode* root,int targetSum,int &count){
        if(root == NULL){
            return;
        }
        solve(root->left,targetSum,count);
        solve(root->right,targetSum,count);
        long long sum = 0;
        secondSolve(root,sum,targetSum,count);
    }
public:
    int pathSum(TreeNode* root, int targetSum) {
        int count  = 0;
        solve(root,targetSum,count);
        return count;
    }
};