// Linear (AC)
class Solution {
   public:
    void reorderList(ListNode *head) {
        vector<ListNode *> v;
        ListNode *cur = head;
        while (cur) {
            v.push_back(cur);
            cur = cur->next;
        }

        cur = head;

        int l = 1, r = v.size() - 1;
        while (l < r) {
            cur->next = v[r--];
            cur = cur->next;
            cur->next = v[l++];
            cur = cur->next;
        }
        if (l == r) {
            cur->next = v[l];
            cur = cur->next;
        }
        cur->next = nullptr;
    }
};

// 找中點，翻轉 Linked list (AC)
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
   public:
    void reorderList(ListNode *head) {
        ListNode *fast = head, *slow = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *cur = slow->next, *prev = nullptr;
        slow->next = nullptr;

        while (cur) {
            ListNode *tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }

        ListNode *cur1 = head->next, *cur2 = prev;

        while (cur1 || cur2) {
            if (cur2) {
                head->next = cur2;
                head = head->next;
                cur2 = cur2->next;
            }
            if (cur1) {
                head->next = cur1;
                head = head->next;
                cur1 = cur1->next;
            }
        }
    }
};