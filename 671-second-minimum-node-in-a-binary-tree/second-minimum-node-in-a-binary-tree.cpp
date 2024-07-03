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
    void find(TreeNode* root,int &mini){
        if(root == NULL){
            return;
        }
        find(root->left,mini);
        if(root -> val < mini){
            mini = root->val;
        }
        find(root->right,mini);
    }
    void find2(TreeNode* root,int &mini,int &mini2,bool &exists){
        if(root == NULL){
            return;
        }
        find2(root->left,mini,mini2,exists);
        if(root -> val > mini && root->val <= mini2){
            mini2 = root->val;
            exists = true;
        }
        find2(root->right,mini,mini2,exists);
    }
    int findSecondMinimumValue(TreeNode* root) {
        int mini = INT_MAX;
        find(root,mini);
        int mini2 = INT_MAX;
        bool exists = false;
        find2(root,mini,mini2,exists);
        if(!exists){
            return -1;
        }
        return mini2;
    }
};