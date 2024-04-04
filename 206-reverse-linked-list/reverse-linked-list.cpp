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
    ListNode* solve(ListNode* head,ListNode* &head2){
        if(head->next == NULL){
            head2 = head;
            return head;
        }
        ListNode* temp = solve(head->next,head2);
        temp->next = head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        
        ListNode* head2 = NULL;
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* last = solve(head,head2);
        last->next = NULL;
        return head2;
    }
};