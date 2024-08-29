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
        int count1 = 0;
        int count2 = 0;
        ListNode* curr1 = headA;
        ListNode* curr2 = headB;
        while(curr1 != NULL){
            curr1 = curr1->next;
            count1++;
        }
        while(curr2 != NULL){
            curr2 = curr2->next;
            count2++;
        }
        curr1 = headA;
        curr2 = headB;
        if(count2 > count1){
            int num = count2-count1;
            while(num){
                curr2 = curr2->next;
                num--;
            }
        }else if(count1 > count2){
            int num = count1-count2;
            while(num){
                curr1 = curr1->next;
                num--;
            }
        }
        while(curr1 != NULL && curr2!= NULL){
            if(curr1 == curr2){
                return curr1;
            }
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        return NULL;
    }
};