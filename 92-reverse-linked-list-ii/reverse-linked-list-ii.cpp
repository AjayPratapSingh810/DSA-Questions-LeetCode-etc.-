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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* curr = head;
        int currcount = 1;
        ListNode* start = NULL;
        ListNode* end = curr;
        while(currcount < left){
            start = curr;
            curr = curr->next;
            currcount++;
        }
        if(start != NULL){
            end = start->next;
        }
        ListNode* prev = NULL;
        ListNode* next = NULL;

        while(currcount <= right){
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            currcount++;
        }
        if(start != NULL){
            start->next = prev;
        }else{
            end->next = curr;
            return prev;
        }
        
            end->next = curr;
        return head;
    }
};