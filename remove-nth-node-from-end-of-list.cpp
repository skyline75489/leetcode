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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        ListNode *p1 = head;
        ListNode *p2 = p1;
        while (n--) {
            p2 = p2->next;
        }
        // Head
        if (p2 == nullptr) {
            ListNode *n = p1->next;
            p1->next = nullptr;
            return n;
        }
        
        while (p2->next != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        // Tail
        if (p1->next == p2) {
            p1->next = nullptr;
            return head;
        }
        // Mid
        else {
            ListNode *tmp = p1->next->next;
            p1->next->next = nullptr;
            p1->next = tmp;
            return head;
        }
    }
};