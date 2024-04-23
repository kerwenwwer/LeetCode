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
    struct cmp
    {
        bool operator()(const ListNode *l, const ListNode *r)
        {
            return l->val > r->val;
        }
    };

    ListNode *mergeKLists(vector<ListNode *> &lists)
    {
        priority_queue<ListNode *, vector<ListNode *>, cmp> pg;
        for (int i = 0; i < lists.size(); i++)
        {
            if (lists[i])
                pg.push(lists[i]);
        }

        ListNode *head = new ListNode(-1);
        ListNode *tmp = head;
        while (pg.size() > 0)
        {
            ListNode *smallest = pg.top();
            pg.pop();
            tmp->next = smallest;
            tmp = tmp->next;

            if (smallest->next)
                pg.push(smallest->next);
        }
        return head->next;
    }
};