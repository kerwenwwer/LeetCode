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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *temp_n = head;
        ListNode *curr = head;
        for(int i = 0; i < n; i++){
            if(curr->next) curr = curr->next;
            else return head->next;
        }
        while(curr->next){
            curr = curr->next;
            temp_n = temp_n->next;
        }
        temp_n->next = temp_n->next->next;

        return head;
    }
};
