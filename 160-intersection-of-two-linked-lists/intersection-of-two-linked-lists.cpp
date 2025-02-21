/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* curr = headA;
        int num1 = 0;
        while(curr!=NULL){
            num1++;
            curr = curr->next;
        }
        int num2 = 0;
        curr = headB;
        while(curr!=NULL){
            num2++;
            curr = curr->next;
        }
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        if(num1 > num2){
            int x = num1-num2;
            while(x){
                curr1 = curr1->next;
                x--;
            }
        }else{
            int x = num2-num1;
            while(x){
                curr2 = curr2->next;
                x--;
            }
        }

        while(curr1 != NULL && curr2 != NULL){
            if(curr1 == curr2){
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
    }
};