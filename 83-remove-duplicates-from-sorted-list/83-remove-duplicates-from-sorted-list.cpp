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
/*
Iterative Approach:
Time Complexity: O(N)
Space Complexity: O(1)
*/
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;
        ListNode *curr = head;
        while(curr!=NULL && curr->next!=NULL){
            if(curr->val == curr->next->val){
                curr->next = curr->next->next;
            }
            else
                curr=curr->next;
        }
        return head;
    }
};