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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;
        bool exists = false;
        while(slow != NULL && fast != NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast == NULL){
                return NULL;
            }
            fast = fast->next;
            if(slow == fast){
                exists = true;
                break;
            }
        }
        if(!exists){
            return NULL;
        }
        slow = head;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};