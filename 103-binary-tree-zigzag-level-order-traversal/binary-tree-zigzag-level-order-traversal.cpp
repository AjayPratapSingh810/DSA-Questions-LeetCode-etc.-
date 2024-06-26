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
    void levelOrderTraversal(TreeNode* root,vector<vector<int>> &ans){
        if (root == NULL) return;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<int> arr;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            if(top == NULL){
                ans.push_back(arr);
                arr.clear();
                if(!q.empty()){
                    q.push(NULL);
                }
            }else{
                arr.push_back(top->val);
                if(top->left != NULL){
                    q.push(top->left);
                }
                if(top->right != NULL){
                    q.push(top->right);
                }
            }
        }
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        levelOrderTraversal(root,ans);
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};