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
    void solve(TreeNode* root,bool l,bool r,int count,int &ans){
        if(root->left == NULL && root->right == NULL){
            return;
        }
        if(root->left){
            if(r == true){
                count++;
                if(count > ans){
                    ans = count;
                }
                solve(root->left,true,false,count,ans);
            }else{
                solve(root->left,true,false,1,ans);
            }
            
        }
        if(root->right){
            if(l == true){
                count++;
                if(count > ans){
                    ans = count;
                }
                solve(root->right,false,true,count,ans);
            }else{
                solve(root->right,false,true,1,ans);
            }
            
        }
    }
    int longestZigZag(TreeNode* root) {
        if(root == NULL || (root ->left == NULL && root->right == NULL)){
            return 0;
        }
        int count = 1;
        int ans = 1;
        if(root ->left){
            solve(root->left,true,false,count,ans);
        }
        count = 1;
        if(root->right){
            solve(root->right,false,true,count,ans);
        }
        return ans;
    }
};