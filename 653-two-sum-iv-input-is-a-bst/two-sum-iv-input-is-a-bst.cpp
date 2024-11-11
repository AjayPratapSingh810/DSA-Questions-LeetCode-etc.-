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
    void inOrderTraversal(TreeNode* root,vector<int> &arr){
        if(root == NULL){
            return;
        }
        inOrderTraversal(root->left,arr);
        arr.push_back(root->val);
        inOrderTraversal(root->right,arr);
    }
    bool findTarget(TreeNode* root, int k) {
        vector<int> arr;
        inOrderTraversal(root,arr);

        int s = 0;
        int e = arr.size()-1;
        while(s<e){
            if(arr[s]+arr[e] == k){
                return true;
            }else if(arr[s]+arr[e] < k){
                s++;
            }else{
                e--;
            }
        }
        return false;
    }
};