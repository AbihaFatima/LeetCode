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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *KthNode, *KthFromEnd=head, *curr=head;
        while(--k) curr=curr->next;
        KthNode = curr;
        
        //gap from KthNode to curr is K
        //Iterating till curr reaches end which would result KthEndNode be at its correct position
        while(curr->next){
            curr=curr->next;
            KthFromEnd = KthFromEnd->next;
        }
        swap(KthNode->val, KthFromEnd->val);
        return head;
    }
};