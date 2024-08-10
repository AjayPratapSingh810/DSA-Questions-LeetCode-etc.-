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
    ListNode* solve(ListNode* head1,ListNode* &head2){
        if(head1->next == NULL){
            head2 = head1;
            return head1;
        }
        ListNode* temp = solve(head1->next,head2);
        temp->next = head1;
        return head1;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head ->next == NULL){
            return head;
        }
        ListNode* head2 = NULL;
        ListNode* a = solve(head,head2);
        a->next = NULL;
        return head2;
    }
};