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
    void solve(map<int,list<int> > &mp,TreeNode* root,int lvl){
        if(root == NULL){
            lvl--;
            return;
        }
        mp[lvl].push_back(root->val);
        solve(mp,root->left,lvl+1);
        solve(mp,root->right,lvl+1);
        lvl--;
        return;
    }
    vector<double> averageOfLevels(TreeNode* root) {
        map<int,list<int> > mp;
        vector<double> vec;
        solve(mp,root,0);
        for(auto i:mp){
            double sum=0;
            double size = 0;
            for(auto j:i.second){
                sum += j;
                size++;
            }
            double ans = sum/size;
            vec.push_back(ans);
        }
        return vec;
    }
};