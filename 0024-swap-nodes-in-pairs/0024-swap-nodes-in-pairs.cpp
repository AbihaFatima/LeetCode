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
//TC:O(N) SC:(N) because of recursion
class Solution {
private:
    ListNode* swapAdjPair(ListNode *head){
        if(!head or !head->next) return head;
        ListNode *first=head, *second=head->next;
        ListNode *tempList = swapAdjPair(second->next);
        
        //Swapping logic
        first->next = tempList;
        second->next = first;
            
        return second;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return swapAdjPair(head);
    }
};