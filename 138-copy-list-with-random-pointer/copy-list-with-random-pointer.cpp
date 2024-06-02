/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   Node* copyRandomList(Node* head) {
        if(head == NULL){
            return head;
        }
        Node* copyHead = NULL;
        Node* pointer = NULL;
        Node* tracker = head;
        while(tracker != NULL){
            int a = tracker->val;
            Node* node = new Node(a);
            if(copyHead == NULL){
                copyHead = node;
                pointer = node;
            }else{
                pointer->next = node;
                pointer = pointer->next;
            }
            tracker = tracker->next;
        }
        Node* prev1 = head;
        Node* next1 = head->next;
        Node* prev2 = copyHead;
        Node* next2 = copyHead->next;

        while(next1 != NULL){
            prev1->next = prev2;
            prev2->next = next1;
            prev1 = next1;
            next1 = prev1->next;
            prev2 = next2;
            next2 = prev2->next;
        }
        prev1->next = prev2;
        prev2->next = NULL;

        Node* curr = head;
        while(curr != NULL){
            if(curr->random != NULL){
                curr->next->random = curr->random->next;
            }
            curr = curr->next->next;
        }

        curr = head;
        Node* curr2 = copyHead;
        while(curr != NULL){
            curr ->next = curr->next->next;
            if (curr2->next != NULL) {
                curr2->next = curr->next->next;
            }
            
            curr = curr->next;
            curr2 = curr2->next;
        }
        return copyHead;
    }
};