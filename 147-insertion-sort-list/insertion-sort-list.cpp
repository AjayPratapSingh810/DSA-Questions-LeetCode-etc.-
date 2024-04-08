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
    void solve(ListNode* node){
        ListNode* min = NULL;
        int minVal = INT_MAX;
        ListNode* temp = node;
        while(temp != NULL){
            if(temp->val < minVal){
                minVal = temp->val;
                min = temp;
            }
            temp = temp->next;
        }
        min->val = node->val;
        node->val = minVal;
    }
    ListNode* insertionSortList(ListNode* head) {
        ListNode* temp = head;
        while(temp != NULL){
            solve(temp);
            temp = temp->next;
        }
        return head;
    }
};