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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue <int, vector<int>, greater<int>> pq;

        for(int i=0;i<lists.size();i++){
            ListNode* curr = lists[i];
            while(curr){
                pq.push(curr->val);
                curr = curr->next;
            }
        }
        ListNode* curr = NULL;
        ListNode* ans = NULL;
        while(!pq.empty()){
            int top = pq.top();
            pq.pop();
            ListNode * l = new ListNode(top);
            if(ans == NULL){
                ans = l;
                curr = l;
            }else{
                curr->next = l;
                curr = curr->next;
            }
        }
        return ans;
    }
};