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
    ListNode *mergeInBetween(ListNode *list1, int a, int b, ListNode *list2)
    {
        ListNode *curr = list1;
        ListNode *be_a = nullptr;
        ListNode *af_b = nullptr;
        int count = 0;
        // Find the node before a and be
        while (curr->next)
        {
            if (count == a - 1)
            {
                be_a = curr;
            }
            else if (count == b)
            {
                af_b = curr->next;
                break;
            }
            curr = curr->next;
            count++;
        }

        // if(be_a && af_b){
        be_a->next = list2;
        curr = list2;
        while (curr)
        {
            if (!curr->next)
            {
                curr->next = af_b;
                break;
            }
            curr = curr->next;
        }
        // }
        return list1;
    }
};