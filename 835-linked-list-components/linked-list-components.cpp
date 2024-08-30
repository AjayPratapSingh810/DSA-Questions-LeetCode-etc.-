/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = true;
        }
        bool add = true;
        int ans = 0;
        ListNode* curr = head;
        while(curr != NULL){
            if(mp[curr->val]){
                if(add){
                    ans++;
                    add = false;
                }
            }else{
                add = true;
            }
            curr = curr->next;
        }
        return ans;
    }
};