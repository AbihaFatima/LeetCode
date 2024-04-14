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
    //TC: O(N) SC:O(1)
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode *curr=head;
        while(curr->next){
            if(curr->val == curr->next->val) curr->next=curr->next->next;
            else curr=curr->next;
        }
        return head;
    }
};