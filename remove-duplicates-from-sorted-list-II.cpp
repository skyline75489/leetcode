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
    ListNode *deleteDuplicates(ListNode *head) {
        ListNode dummy(-1);
        ListNode *p = &dummy;
        ListNode *p1, *p2;
        p1 = p2 = nullptr;
        p->next = head;
        
        p1 = &dummy;
        p2 = p1->next;
        
        bool duplicated = false;
        while ( p1 && p2 && p2->next) {
            duplicated = false;
            while (p2->next && p2->next->val == p2->val) {
                ListNode *d = p2->next;
                delete p2;
                p2 = d;
                duplicated = true;
            }
            if (duplicated) {
                ListNode *d = p2->next;
                delete p2;
                p2 = d;
                p1->next = p2;
                continue;
            }
            p1->next = p2;
            p2 = p2->next;
            p1 = p1->next;
        }
        return dummy.next;
    }
};