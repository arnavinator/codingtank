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

#include <stack>
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        // handle case of empty list
        if (head == nullptr)
            return head; 
        
        stack<int> stack;
        // iterate over all items of list, and add them to stack
        while (head->next != nullptr) {
            stack.push(head->val);
            head = head->next;
        }
        stack.push(head->val);  // last val to add to stack
        
        // since stack is LIFO, popping out will be in reverse order
        // use current as head as starting point
        ListNode* rev = head;
        while (!stack.empty()) {
            rev->next = new ListNode(stack.top());
            stack.pop();
            rev = rev->next;
        }
        
        return head->next;
    }
};
