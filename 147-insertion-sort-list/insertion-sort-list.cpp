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
    ListNode* insertionSortList(ListNode* head) {
     vector<int> arr;
     ListNode* temp = head;
     while(temp != NULL){
        arr.push_back(temp->val);
        temp = temp->next;
     }   

     for(int i = 1;i<arr.size();i++){
        for(int j = i;j>0;j--){
            if(arr[j] < arr[j-1]){
                swap(arr[j],arr[j-1]);
            }
        }
     }
     temp = head;
     int i = 0;
     while(temp != NULL){
        temp->val = arr[i++];
        temp = temp->next;
     }
     return head;
    }
};