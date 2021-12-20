/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <vector> 
using namespace std;

class Solution {
public:
    bool hasCycle(ListNode *head) {
        // case where linked list is empty
        if (head == NULL) {
            return false;
        }
        // go thru all the nodes, and store address in map
        vector mem_arr {head};
        ListNode *next_addr = head->next;
        
        
        // address case where more than 2 nodes
        while (next_addr != NULL) {
            // check if next_addr previously seen
            for (int i = 0; i < mem_arr.size(); i++) {
                if (mem_arr[i] == next_addr) {
                    return true;
                }
            }
            // if not seen, add it to list of seen addr
            mem_arr.push_back(next_addr);
            // go to the next addr in list
            next_addr = (next_addr->next);
        }
        
        // otherwise, all cases failed and no cycle
        return false;
        
    }
};
