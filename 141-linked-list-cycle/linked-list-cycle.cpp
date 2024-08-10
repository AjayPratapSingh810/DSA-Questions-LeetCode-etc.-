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
    bool hasCycle(ListNode *head) {
        if(head == NULL || head->next == NULL){
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head->next;
        if(slow == fast){
            return true;
        }
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
            if(slow == fast){
                return true;
            }
            if(fast == NULL){
                return false;
            }
            if(fast -> next != NULL){
                fast = fast->next;
            }
            if(slow == fast){
                return true;
            }
            if(fast == NULL){
                return false;
            }

        }
        return false;
    }
};