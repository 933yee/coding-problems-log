class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode *cur = head, *prev = nullptr;
        while (cur) {
            ListNode* tmp = cur->next;
            cur->next = prev;
            prev = cur;
            cur = tmp;
        }
        return prev;
    }
};