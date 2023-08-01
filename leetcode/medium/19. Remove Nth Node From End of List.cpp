// 算出有幾個node
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        int sz = 0;
        ListNode* cur = head;
        while (cur) {
            cur = cur->next;
            sz++;
        }
        int k = sz - n;
        cur = dummy;
        while (k--) {
            cur = cur->next;
        }
        cur->next = cur->next->next;
        return dummy->next;
    }
};

// two pointers
// 當fast到底時，slow剛好在要移除的node的前面
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* dummy = new ListNode(0, head);
        ListNode *fast = dummy, *slow = dummy;
        for (int i = 0; i <= n; i++) {
            fast = fast->next;
        }
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return dummy->next;
    }
};
