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
        // recursive approach!
        // keep traversing to end of list
        // once at end, this is new_head
        // then, begin reassigning next vals
        //      make tail->next = predecessor
        //      make predecessor->next = nullptr so not a loop between predecessor and tail
        
        if (head==nullptr || head->next==nullptr) {
            return head;
        }
        // this line will keep executing until we are at end of original list
        // new_head is the pointer we want to return, so we keep passing it 
        //      down the line of recursions... however, without the later steps, 
        //      the order would not be swapped!
        ListNode* new_head = reverseList(head->next); 
        
        // in every recursive run, head->next represents the tail
        // head->next is a different node based on which iteration of reverseList we are on
        // however, new_head will always be the same
        // make tail->next = predecessor and predecessor->next = nullptr so not a loop between predecessor and tail
        head->next->next = head;
        head->next = nullptr;
        
        // return new_head so that we remember the start pos once all done swapping
        return new_head;
    }
};
