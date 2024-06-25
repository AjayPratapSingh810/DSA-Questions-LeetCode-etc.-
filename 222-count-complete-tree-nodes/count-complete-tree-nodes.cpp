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
    int solve(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        int lc = 0;
        int rc = 0;
        TreeNode* curr = root;

        while(curr != NULL){
            curr = curr->left;
            lc++;
        }
        curr = root;
        while(curr != NULL){
            curr = curr->right;
            rc++;
        }

        if(lc == rc){
            return pow(2,lc)-1;
        }
        return (1+solve(root->left)+solve(root->right));
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        return solve(root);
    }
};