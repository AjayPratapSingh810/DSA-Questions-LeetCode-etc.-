/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* curr = node;
        ListNode* prev = NULL;
        int n = node -> val;
        while(curr->val == n){
            if(curr -> next == NULL){
                if(prev != NULL){
                    prev->next = NULL;
                    break;
                }
            }
            int val = curr->val;
            curr->val = curr->next->val;
            curr->next->val = val;
            prev = curr;
            curr = curr->next;
        }
    }
};