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
    ListNode* reverseList(ListNode* head) {
                // Iterative Approach
        ListNode *Curr = head;
        ListNode *Prev = NULL;
        ListNode *NextNode;
        
        while(Curr!=NULL){
            NextNode = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = NextNode;
        }
        // head = Prev;
        return Prev;
    }
};