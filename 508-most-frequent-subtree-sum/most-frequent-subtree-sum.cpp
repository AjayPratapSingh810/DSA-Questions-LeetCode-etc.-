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
    int solve(TreeNode* root,unordered_map<int,int> &mp){
        if(root == NULL){
            return 0;
        }
        int lt = solve(root->left,mp);
        int rt = solve(root->right,mp);
        int sum = lt+rt+root->val;
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> mp; 
        solve(root,mp);
        int maxi = -1;
        for(auto i : mp){
            if(i.second > maxi){
                maxi = i.second;
            }
        }
        vector<int> arr;
        for(auto j : mp){
            if(j.second == maxi){
                arr.push_back(j.first);
            }
        }
        return arr;
    }
};