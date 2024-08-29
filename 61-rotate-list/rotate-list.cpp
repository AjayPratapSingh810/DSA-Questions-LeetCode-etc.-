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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL){
            return head;
        }
        ListNode* curr = head;
        int count = 0;
        while(curr != NULL){
            count++;
            curr = curr->next;
        }
        int num = k%count;
        while(num){
            ListNode* curr = head;
            ListNode* prev = NULL;
            while(curr->next != NULL){
                prev = curr;
                curr = curr->next;
            }
            prev->next = NULL;
            curr->next = head;
            head = curr;
            num--;
        }
        return head;

    }
};