#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}; // 构造函数
};

ListNode* merge(ListNode* l1, ListNode *l2) {
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

ListNode* mergeSort(ListNode* head) {
	if (!head || !head->next) {
		return head;
	}
	ListNode* fast = head, *slow = head;

	while (fast->next && fast->next->next) {
		fast = fast->next->next;
		slow = slow->next;
	}

	fast = slow; // 奇数个元素时，slow指向中间元素，偶数个元素时，slow指向前半段后一个元素
	slow = slow->next;
	fast->next = NULL;

	ListNode* l1 = mergeSort(head);
	ListNode* l2 = mergeSort(slow);
	return merge(l1, l2);

}

ListNode* createNode(int a[], int n) {
	// cout << "Hello There!" << endl;
	// cout << a[0] << endl;

	ListNode *dummy = new ListNode(-1);
	ListNode *cur = dummy;
	for (int i = 0; i < n; i++) {
		ListNode* temp = new ListNode(a[i]);
		cur->next = temp;
		cur = temp;
	}
	return dummy->next;
}

int main() {
	int a[9] = {3, 1, 2, 4, 5, 6, 7, 8, 9};
	ListNode* root = createNode(a, 9);

	sortList(root);

	// ListNode* head = root;
	while (root) {
		cout << root->val << "\t";
		root = root->next;
	}

	// 这个代码里，结果少了前面两个数，但是在Leetcode上是可以过的，还需要再debug一下
	cout << endl;
	return 0;
}

