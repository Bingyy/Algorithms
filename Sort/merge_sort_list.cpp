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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(-1);
        ListNode* cur = dummy;
        while (l1 && l2) {
            if (l1->val < l2->val) {
                cur->next = l1;
                cur = l1;
                l1 = l1->next;
                
            } else {
                cur->next = l2;
                cur = l2;
                l2 = l2->next;   
            }
        }
        
        if (l1) {
            cur->next = l1;
        } 
        if (l2) {
            cur->next = l2;
        }
        
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) {
        // 归并排序，找到中间结点的方法是：快慢指针
        if (!head || !head->next) {
            return head;
        }
        ListNode* fast = head, *slow = head;
        // 奇数个元素时，slow结束时指向中间元素
        // 偶数个元素时，slow结束时指向前半段的最后一个元素，所以需要slow = slow->next
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        
        // 断开成两部分
        fast = slow;
        slow = slow->next;
        fast->next = nullptr;
        
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergeTwoLists(l1, l2);
    
    }
};  // https://bingw.blog.csdn.net/article/details/87903783
