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
    bool isPalindrome(ListNode* head) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL){
            curr = curr->next;
            count++;
        }
        int mid = count/2;
        stack<int> st;
        curr = head;
        while(mid){
            st.push(curr->val);
            curr = curr->next;
            mid--;
        }
        if(count%2 == 1){
            curr = curr->next;
        }
        while(curr != NULL){
            int top = st.top();
            if(curr->val != top){
                return false;
            }
            curr = curr->next;
            st.pop();
        }
        return true;

    }
};