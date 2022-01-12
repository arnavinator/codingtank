
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int first, second, sum;
        bool carry {false};
        ListNode head;
        ListNode *tail = &head;
        while (l1 != nullptr || l2 != nullptr || carry==true) {
            if (l1) {
                first = l1->val;
                l1 = l1->next;
            }
            else
                first = 0;
            
            if (l2) {
                second = l2->val;
                l2 = l2->next;
            }
            else
                second = 0;
            
            if (carry)
                sum = first+second+1;
            else
                sum = first+second;
            
                        
            if (sum/10 == 1) {
                carry = true;
            } else {
                carry = false;
            }
            tail->next = new ListNode(sum%10);
            tail = tail->next;

        }
        return head.next;
    }
};
