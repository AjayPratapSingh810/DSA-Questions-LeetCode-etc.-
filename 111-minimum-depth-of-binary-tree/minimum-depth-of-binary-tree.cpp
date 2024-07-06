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
    int minDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int depth = 1;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL){
                depth += 1;
            }
            if(top == NULL && !q.empty()){
                q.push(NULL);
                continue;
            }
           

            if(top -> left == NULL && top->right  == NULL){
                return depth;
            } 
            if(top->left){
                q.push(top->left);
            }
            if(top->right){
                q.push(top->right);
            }
        }
        return -1;
    }
};