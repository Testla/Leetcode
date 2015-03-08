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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *head, **current = &head;
        int carry = 0, sum;
        while (l1 && l2) {
            sum = l1->val + l2->val + carry;
            *current = new ListNode(sum % 10);
            carry = sum / 10;
            current = &(*current)->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 || l2) {
            ListNode *longer = l1 ? l1 : l2;
            while (longer) {
                sum = longer->val + carry;
                *current = new ListNode(sum % 10);
                carry = sum / 10;
                current = &(*current)->next;
                longer = longer->next;
            }
        }
        if (carry)
            *current = new ListNode(carry);
        return head;
    }
};

