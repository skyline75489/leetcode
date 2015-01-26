/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
总体思路是把大的和小的分别拿出来，单独搞两个链表
最后再把两个链表头尾相接，合并上。
*/
class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        if (head == nullptr) {
            return nullptr;
        }
        
        ListNode head_dummy = ListNode(-1);
        ListNode *prev = &head_dummy;
        ListNode *tail = nullptr;
        
        ListNode greater_head_dummy = ListNode(-1);
        ListNode *greater_prev = &greater_head_dummy;
        
        ListNode *p = head;
        while (p != nullptr) {
            if (p->val < x) {
                prev->next = p;
                prev = p;
                p = p->next;
                prev->next = nullptr;
                
            } else {
                greater_prev->next = p;
                greater_prev = p;
                p = p->next;
                greater_prev ->next = nullptr;
            }
        }
        
        prev->next = greater_head_dummy.next;
        return head_dummy.next;

    }
};