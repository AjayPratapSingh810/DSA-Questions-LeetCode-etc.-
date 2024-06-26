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
    void solve(TreeNode* root,vector<int> &ans,int lvl,int sum){
        if(root == NULL){
            lvl--;
            return;
        }
        if(root->left == NULL && root->right == NULL){
            sum = sum * 10;
            sum = sum +root->val;
            ans.push_back(sum);
            sum = sum/10;
            lvl--;
            return;
        }
        sum = sum * 10;
        sum = sum +root->val;
        solve(root->left,ans,lvl+1,sum);
        solve(root->right,ans,lvl+1,sum);

        sum = sum/10;
        lvl--;
        return;
    }
    int sumNumbers(TreeNode* root) {
        vector<int> ans;
        solve(root,ans,0,0);
        int answer = 0;
        for(int i=0;i<ans.size();i++){
            answer = answer+ans[i];
        }
        return answer;
    }
};