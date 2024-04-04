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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* temp = head;
        ListNode* head2 = head;
        while(temp != NULL){
            count ++;
            temp = temp->next;
        }
        if(count == 1){
            return NULL;
        }
        int place = count/2;
        temp = head;
        ListNode* prev = NULL;
        while(place){
            prev = temp;
            temp = temp->next;
            place--;
        }

        prev->next = temp->next;
        temp->next  = NULL;
        return head2;

    }
};