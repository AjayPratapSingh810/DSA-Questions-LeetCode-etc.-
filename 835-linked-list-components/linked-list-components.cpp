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
        vector<int> travel;
        ListNode* curr = head;
        int sum = 0;
        while(curr != NULL){
            travel.push_back(curr->val);
            curr = curr->next;
        }
        unordered_map<int,bool> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]] = true;
        }
        bool nya = true; 
        int ans = 0;
        for(int i=0;i<travel.size();i++){
            if(mp[travel[i]]){
                if(nya){
                    nya = false;
                    ans++;
                }
            }else{
                nya = true;
            }
        }
        return ans;
    }
};