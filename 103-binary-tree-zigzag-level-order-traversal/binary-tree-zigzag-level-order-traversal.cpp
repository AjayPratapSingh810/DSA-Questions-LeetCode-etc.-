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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        vector<vector<int> > ans;
        vector<int> arr;
        if(root == NULL){
            return ans;
        }
        int count = 0;
        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();
            if(top == NULL){
                if(count%2 == 1){
                    reverse(arr.begin(),arr.end());
                }
                ans.push_back(arr);
                arr.clear();
                if(q.size()){
                    q.push(NULL);
                }
                count++;
            }else{
                arr.push_back(top->val);
                if(top->left){
                    q.push(top->left);
                }
                if(top->right){
                    q.push(top->right);
                }
            }

        }
        return ans;
    }
};