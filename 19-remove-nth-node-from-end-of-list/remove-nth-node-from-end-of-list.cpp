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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }

        int dest = count - n;
        if(dest == 0){
            return head->next;
        }
        int count2 = 1;
        curr = head;
        while(count2 != dest){
            curr = curr->next;
            count2++;
        }
        if(curr->next->next != NULL){
            curr->next = curr->next->next;
        }else{
            curr->next = NULL;
        }
        return head;
    }
};