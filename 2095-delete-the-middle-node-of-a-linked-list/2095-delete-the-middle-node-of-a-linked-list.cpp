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
    ListNode* deleteMiddle(ListNode* head) {
        int count = 0;
        ListNode* tmp = head;
        ListNode* curr = head;
        while(tmp)
        {
            count++;
            tmp = tmp->next;
        }
        if(count == 1) return NULL;
        int k = count/2-1;
        while(k--)
        {
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};