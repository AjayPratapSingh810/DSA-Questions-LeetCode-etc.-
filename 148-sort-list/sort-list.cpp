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
    ListNode* merge(ListNode* a,ListNode* b){
        ListNode* curr1 = a;
        ListNode* curr2 = b;

        ListNode* ans = NULL;
        ListNode* curr = NULL;

        while(a!=NULL && b!= NULL){
            ListNode* x = NULL;
            if(a->val < b->val){
                x = new ListNode(a->val);
                a = a->next;
            }else{
                x = new ListNode(b->val);
                b = b->next;
            }
            if(ans == NULL){
                curr = x;
                ans = curr;
            }else{
                curr->next = x;
                curr = curr->next;
            }
        }
        while(a!=NULL){
            ListNode* x = NULL;
                x = new ListNode(a->val);
                a = a->next;
            
            if(ans == NULL){
                curr = x;
                ans = curr;
            }else{
                curr->next = x;
                curr = curr->next;
            }
        }
        while(b!=NULL){
            ListNode* x = NULL;
                x = new ListNode(b->val);
                b = b->next;
            
            if(ans == NULL){
                curr = x;
                ans = curr;
            }else{
                curr->next = x;
                curr = curr->next;
            }
        }
        return ans;
    }
    ListNode* sortList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return head;
        }   
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* temp = NULL;

        while(fast != NULL && fast->next != NULL){
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* L = sortList(head);
        ListNode* R = sortList(slow);

        return merge(L,R);
    }
};