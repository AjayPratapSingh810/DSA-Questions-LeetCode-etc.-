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
        if(head == NULL || head->next == NULL){
            return NULL;
        }
        int count = -1;
        ListNode* curr = head;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        int mid = count/2;
        if(count % 2 == 1){
            mid++;
        }
        curr = head;
        while(mid){
            mid--;
            if(mid == 0){
                curr->next = curr->next->next;
            }else{
                curr = curr->next;
            }
        }
        return head;
    }
};