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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast=head, *slow=head, *pre=NULL;
        for ( int i=1; i<n; ++i ) {
            fast=fast->next;
            if ( fast==NULL ) {
                return head;
            }
        }
        while( fast->next!= NULL ) {
            fast = fast->next;
            pre=slow;
            slow = slow->next;
        }
        if ( pre ) {
            pre->next = slow->next;
        }
        else {
            head = head->next;
        }
        return head;
    }
};
