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
    ListNode* deleteDuplicates(ListNode* head) {
        // if only one node in the list, then return the list
        if (head == NULL || head->next == NULL) {
            return head;
        }
        
        // just look at next node, if its same value then delete, else move forward
        ListNode *current {head};
        ListNode *future {head->next};
        
        
        while (future->next != NULL) {
            // if next node same val as head, then change the next of head to skip over
            if (future->val == current->val) {
                future = future->next;
                current->next = future;
            } else {  // otherwise, don't need update head's next, just iterate to next head/future
                current = current->next;
                future = future->next;
            }
        }
        
        // consider the end case where last two nodes are equal
        if (future->val == current->val) {
            current->next = NULL; // remove last node
        }
        
        return head;
    }
};
