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
    ListNode *swapPairs(ListNode *head) {
        if (head == nullptr) {
            return head;
        }
        ListNode *p1, *p2, *newHead;
        p1 = head;
        p2 = p1->next != nullptr ? p1->next : p1;
        newHead = p2;
        
        while (p1 && p2) {
            ListNode *tmp = p2;
            ListNode *next1 = tmp->next;
            ListNode *next2 = tmp->next != nullptr ? tmp->next->next : nullptr;
            p2->next = p1;
            p1->next = next2;
            
            p1 = next1;
            if (p1 != nullptr && p1->next != nullptr) {
                p2 =  p1->next;
            } else {
                while (p2->next) {
                    p2 = p2->next;
                }
                p2->next = p1;
                break;
            }
        }
        return newHead;
    }
};