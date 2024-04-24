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
class Solution
{
public:
    ListNode *reverseList(ListNode *head)
    {
        if (!head || !head->next)
        {
            return head; // empty
        }
        ListNode *prev = 0;
        ListNode *curr = head;
        ListNode *prec = head->next;

        while (prec)
        {
            curr->next = prev;
            prev = curr;
            curr = prec;
            prec = prec->next;
        }

        curr->next = prev;
        head = curr;
        return head;
    }
};