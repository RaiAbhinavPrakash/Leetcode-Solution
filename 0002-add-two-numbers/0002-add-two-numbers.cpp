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
    ListNode* reverse(ListNode* ll)
    {
        ListNode* curr = NULL, *prev = NULL;
        while(ll != NULL)
        {
            curr = ll->next;
            ll->next = prev;
            prev = ll;
            ll = curr;
        }
        return prev;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* t1 = l1, *t2 = l2, *ans = NULL;
        int n1 = 0, n2 = 0, carry = 0;
        while(t1 != NULL)
        {
            n1++;
            t1 = t1->next;
        }
        while(t2 != NULL)
        {
            n2++;
            t2 = t2->next;
        }
        ListNode* temp;
        if(n2>n1)
        {
            temp = l2;
            l2 = l1;
            l1 = temp;
        }
        while(l1 != NULL  &&  l2 != NULL)
        {
            int k = l1->val+l2->val+carry;
            ListNode* curr = new ListNode(k%10);
            curr->next = ans;
            ans = curr;
            carry = k/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1 != NULL)
        {
            int k = l1->val+carry;
            ListNode* curr = new ListNode(k%10);
            curr->next = ans;
            ans = curr;
            carry = k/10;
            l1 = l1->next;
        }
        if(carry)
        {
            ListNode* curr = new ListNode(carry);
            curr->next = ans;
            ans = curr;
        }
        ListNode* ans1 = reverse(ans);
        return ans1;
    }
};