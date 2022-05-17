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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = new ListNode(0);
        ListNode *p1 = l1, *p2 = l2, *p3 = l3;
        int carry = 0;
        
        while(p1 && p2){
            int tmp = p1->val + p2->val + carry;
            carry = tmp / 10;
            p3->next = new ListNode(tmp % 10);
            
            p1 = p1->next;
            p2 = p2->next;
            p3 = p3->next;
        }
        
        while(p1 || p2 || carry){
            int tmp = carry;
            if(p1) {
                tmp += p1->val;
                p1 = p1->next;
            }else if (p2) {
                tmp += p2->val;
                p2 = p2->next;
            }
            
            carry = tmp / 10;
            p3->next = new ListNode(tmp % 10);
            p3 = p3->next;
        }
        return l3->next;
    }
};
