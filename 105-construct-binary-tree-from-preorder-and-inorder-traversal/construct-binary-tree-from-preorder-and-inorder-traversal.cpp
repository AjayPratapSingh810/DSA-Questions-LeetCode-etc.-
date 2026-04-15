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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int &index,int x, int y){
        if(index >= inorder.size() || x>y){
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[index]);
        int k = 0;
        for(int i = 0;i<inorder.size();i++){
            if(inorder[i] == preorder[index]){
                k = i;
                break;
            }
        }
        index++;
        root->left = solve(preorder,inorder,index,x,k-1);
        root->right = solve(preorder,inorder,index,k+1,y);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        return solve(preorder,inorder,index,0,n-1);
    }
};