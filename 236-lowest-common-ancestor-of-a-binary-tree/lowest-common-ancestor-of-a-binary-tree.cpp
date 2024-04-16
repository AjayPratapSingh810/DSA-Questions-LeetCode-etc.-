/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void findNodes(TreeNode* root,stack<int> &st,TreeNode* p){
        if(root == NULL){
            return;
        }
        if(st.empty() || st.top() != p->val){
            st.push(root->val);
        }
        findNodes(root->left,st,p);
        findNodes(root->right,st,p);
        if(!st.empty() && st.top() != p->val){
            st.pop();
        }
    }
    TreeNode* solve(TreeNode* root,int data){
        if(root == NULL){
            return NULL;
        }
        if(root->val == data){
            return root;
        }
        TreeNode* l = NULL;
        TreeNode* r = NULL;
        l = solve(root->left,data);
        r = solve(root->right,data);
         if(l == NULL && r != NULL){
            return r;
        }else if(l != NULL && r== NULL){
            return l;
        }
        return NULL;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<int> s1;
        stack<int> s2;
        s1.push(root->val);
        s2.push(root->val);
        findNodes(root,s1,p);
        findNodes(root,s2,q);
        int ansData = -1;
        unordered_map<int,bool> mp;
        while(!s1.empty()){
            mp[s1.top()] = true;
            s1.pop();
        }
        while(!s2.empty()){
            if(mp[s2.top()]){
                ansData = s2.top();
                break;
            }
            s2.pop();
        }

        return solve(root,ansData);
    }
};