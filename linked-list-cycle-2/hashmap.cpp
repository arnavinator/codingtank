/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL) {
            return NULL;
        }
        
        // instead of vector, unordered_map since hash table is O(1) as opposed to O(n) search in vector
        unordered_map<ListNode*,bool> umap {};
        
        // use head to iterate instead of wasting memory on new var new_addr
        while(head != NULL){
            // if umap has seen the head, print true
            if (umap.find(head) != umap.end()) {
                return head;
            } else {  // otherwise, add the address to umap
                umap[head] = true;
                head = head->next;
            }
        }
        
        // no cycle found, return false
        return NULL;

    }
};
