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
    TreeNode* solve(vector<int>& preOrder,vector<int> &inOrder,int s,int e,int &p){
        if(s>e){
            return NULL;
        }
        if(s==e){
            TreeNode* a = new TreeNode(preOrder[p++]);
            return a;
        }
        TreeNode* a = new TreeNode(preOrder[p++]);
        int x = -1;
        for(int i= 0;i<inOrder.size();i++){
            if(inOrder[i] == a->val){
                x = i;
                break;
            }
        }
        a->left = solve(preOrder,inOrder,s,x-1,p);
        a->right = solve(preOrder,inOrder,x+1,e,p);
        return a;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        vector<int> inOrder = preorder;
        sort(inOrder.begin(),inOrder.end());
        int n = preorder.size()-1;
        int p =0;
        return solve(preorder,inOrder,0,n,p);
    }
};