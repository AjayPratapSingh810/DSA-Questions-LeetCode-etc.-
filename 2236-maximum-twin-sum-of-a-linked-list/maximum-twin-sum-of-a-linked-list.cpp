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
    int pairSum(ListNode* head) {
        unordered_map<int,int> mp;
        ListNode* temp = head;
        int count = 0;
        while(temp != NULL){
            mp[count++] = temp->val;
            temp = temp->next;
        }
        int twinSum = INT_MIN;
        for(int i = 0;i<=count/2-1;i++){
            int broInd = (count - 1- i);
            int sum = mp[i]+mp[broInd];
            if(sum > twinSum){
                twinSum = sum;
            }
        }
        return twinSum;
    }
};