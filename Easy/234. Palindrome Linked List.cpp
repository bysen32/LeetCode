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
    bool isPalindrome(ListNode* head) {
        ListNode* rev,* temp,* fast,* slow;
        slow = fast = head;
        temp = rev = NULL;
        while ( fast && fast->next ) {
            fast = fast->next->next;
            temp = slow->next;
            slow->next = rev;
            rev = slow;
            slow = temp;
        }
        if (fast) {
            slow = slow->next;
        }
        while (rev) {
            if ( rev->val != slow->val ) {
                return false;
            }
            rev = rev->next;
            slow = slow->next;
        }
        return true;
    }
};
