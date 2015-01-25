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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        ListNode *result = nullptr; // 头指针
        ListNode *presult = nullptr; // 当前
        ListNode *last = nullptr; // 尾指针
        
        int carry, val1, val2, sum;
        carry = val1 = val2 = sum = 0;
        while (p1 || p2) {
            val1 = p1 == nullptr ? 0 : p1->val;
            val2 = p2 == nullptr ? 0 : p2->val;
            
            sum = val1 + val2 + carry;
            ListNode *a = new ListNode(sum % 10);
            if (result == nullptr) {
                result = a;
                presult = result;
            } else {
                presult->next = a;
                presult = a;
            }
            last = presult;

            carry = sum / 10;
            
            if (p1) {
                p1 = p1->next;
            }
            if (p2) {
                p2 = p2->next;
            }
        }
        if (carry > 0) {
            ListNode *p = new ListNode(carry);
            last->next = p;
        }
        return result;
    }
};