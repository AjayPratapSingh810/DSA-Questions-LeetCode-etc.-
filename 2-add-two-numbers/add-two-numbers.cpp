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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* curr1 = l1;
        ListNode* curr2 = l2;

        while(curr1 != NULL && curr2 != NULL){
            int sum = carry + curr1->val + curr2->val;
            carry = sum/10;
            sum = sum%10;
            curr1->val = sum;
            curr1= curr1->next;
            curr2= curr2->next;
        }
        if(curr2 != NULL){
            curr1 = l1;
            while(curr1->next != NULL){
                curr1 = curr1->next;
            }
            curr1->next = curr2;
            curr1 = curr1->next;
        }
        while(carry && curr1 != NULL){
            int sum = carry + curr1->val;
            carry = sum/10;
            sum = sum%10;
            curr1->val = sum;
            curr1= curr1->next;
        }
        if(carry){
            curr1 = l1;
            while(curr1->next != NULL){
                curr1 = curr1->next;
            }
            curr1->next = new ListNode(carry);
        }
        return l1;
    }
};