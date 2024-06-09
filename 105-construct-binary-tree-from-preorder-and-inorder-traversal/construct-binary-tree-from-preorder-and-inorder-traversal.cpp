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
    int findIndex(int val,vector<int> inorder){
        for(int i=0;i<inorder.size();i++){
            if(val == inorder[i]){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(TreeNode* root,int &index,vector<int> &preorder,vector<int> &inorder,int l,int r){
        if(l>r || index >= preorder.size()){
            return NULL;
        }
        int indi = findIndex(preorder[index],inorder);
        root = new TreeNode(preorder[index++]);

        root->left = solve(root->left,index,preorder,inorder,l,indi-1);
        root->right = solve(root->right,index,preorder,inorder,indi+1,r);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode* root;
        int index = 0;
        return solve(root,index,preorder,inorder,0,preorder.size()-1);
    }
};