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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* ans = head;
        if(head == NULL){
            return head;
        }
        ListNode* h1 = head;
        ListNode* h2 = head->next;
        if(h2 == NULL || h2->next == NULL){
            return head;
        }
        ListNode* temp = head->next;

        while(h2 != NULL){
            if(h2 -> next == NULL){
                break;
            }
            h1 -> next = h2 -> next;
            h1 = h1 -> next;
            h2 -> next = h1 -> next;
            h2 = h2->next; 
        }
        h1->next = temp;
        return ans;

    }
};