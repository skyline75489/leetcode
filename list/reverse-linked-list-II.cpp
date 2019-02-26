/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:

    void doReverse(ListNode *start, ListNode *end, int step) {
        ListNode *p1, *p2;
        p1 = start;
        p2 = p1->next;
        
        p1->next = nullptr;
        
        while (step--) {
            ListNode *tmp = p2;
            ListNode *tmp2 = p2->next;
            p2->next = p1;
            p1 = tmp;
            p2 = tmp2;
        }
    }

public:
    ListNode *reverseBetween(ListNode *head, int m, int n) {
        int step = n - m;
        if (step == 0) {
            return head;
        }
        ListNode dummy(-1);
        dummy.next = head;
        ListNode *p = &dummy;
        ListNode *start, *end, *reversePrev, *reverseNext;
        start = end = reversePrev = reverseNext= nullptr;
        while (m-- && n--) {
            reversePrev = p;
            p = p->next;
        }
        start = p;
        while (n--) {
            p = p->next;
        }
        end = p;
        reverseNext = p->next;
        
        doReverse(start, end, step);
        
        reversePrev->next = end;
        start->next = reverseNext;
        
        return dummy.next;
    }
};