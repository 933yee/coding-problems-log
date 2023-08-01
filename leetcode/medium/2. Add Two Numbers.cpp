class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* dummy = new ListNode(0, l1);
        ListNode* prev = dummy;
        while (l1 || l2) {
            if (l1 && l2) {
                l1->val += l2->val + carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                prev = l1;
                l1 = l1->next;
                l2 = l2->next;
            } else if (l1) {
                l1->val += carry;
                carry = l1->val / 10;
                l1->val = l1->val % 10;
                prev = l1;
                l1 = l1->next;
            } else if (l2) {
                l2->val += carry;
                carry = l2->val / 10;
                l2->val = l2->val % 10;
                prev->next = l2;
                prev = l2;
                l2 = l2->next;
            }
        }
        if (carry) prev->next = new ListNode(carry, nullptr);
        return dummy->next;
    }
};