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
        if(head == NULL){
            return NULL;
        }
        int count = 0;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        if(n == count){
            return head->next;
        }
        count = count-n;
        curr = head;
        while(count){
            count--;
            if(count == 0){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};