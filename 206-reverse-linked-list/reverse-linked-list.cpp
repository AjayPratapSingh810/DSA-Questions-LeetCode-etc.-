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
    ListNode* solve(ListNode* &head,ListNode* &ans){

        if(head->next == NULL){
            ans = head;
            return head;
        }
        ListNode* curr = solve(head->next,ans);
        curr -> next = head;
        return head;
    }
    ListNode* reverseList(ListNode* head) {
        if(head == NULL){
            return NULL;
        }
        ListNode* ans = NULL;
        ListNode* a = solve(head,ans);
        a->next = NULL;
        return ans;
    }
};