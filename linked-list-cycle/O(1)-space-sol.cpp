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
        if (head == NULL) {
            return false;
        }
        // walker traverses one node at a time
        ListNode walker = head;
        // runner traverses two nodes at a time
        ListNode runner = head;
        
        // if there exists a cycle in our list, then runner will never be null
        // no need for memory, runner will cycle back and equal walker at some point
        while(runner.next!=null && runner.next.next!=null) {
            walker = walker.next;
            runner = runner.next.next;
            if(walker==runner) return true;
        }
        // if we ever reach a node with no next link upcoming, no cycle!
        return false;

        
    }
};
