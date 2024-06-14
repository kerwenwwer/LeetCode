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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupPrev = dummy;

        while(true){
            // Find the k'th node;
            ListNode *kth = getKth(groupPrev, k);
            if(!kth) break;
            ListNode *groupNext = kth->next;
            
            // Reverse the group
            ListNode *prev = kth->next, *curr = groupPrev->next;
            ListNode *temp = NULL;

            while(curr != groupNext){
                temp = curr->next;
                curr->next = prev;
                prev = curr;
                curr = temp;
            }

            // Re connect the linked-list
            temp = groupPrev->next;
            groupPrev->next = kth;
            groupPrev = temp;
        }

        // Delete dummy to avoid memory leak
        ListNode* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
private:
    ListNode* getKth(ListNode* curr, int k){
        while(curr && k > 0){
            curr = curr->next;
            k--;
        }
        return curr;
    }
};
