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

//TC: O(N) SC:O(1)
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *dummy = new ListNode(0);
        dummy->next = head;
        ListNode *curr = dummy;
        while(curr->next and curr->next->next){
            ListNode *first = curr->next;
            ListNode *second = curr->next->next;
            first->next = second->next;
            second->next = first;
            curr->next = second;
            curr = curr->next->next;
        }
        return dummy->next;
    }
};