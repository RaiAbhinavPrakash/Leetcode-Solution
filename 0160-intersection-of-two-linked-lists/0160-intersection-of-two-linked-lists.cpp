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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *temp1 = headA, *temp2 = headB;
        int c1 = 0, c2 = 0;
        while(temp1)
        {
            c1++;
            temp1 = temp1->next;
        }
        while(temp2)
        {
            c2++;
            temp2 = temp2->next;
        }
        while(c1>c2)
        {
            headA = headA->next;
            c1--;
        }
        while(c2>c1)
        {
            headB = headB->next;
            c2--;
        }
        while(headA && headB)
        {
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
};