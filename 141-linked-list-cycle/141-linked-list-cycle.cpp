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
    //TimeComplexity O(N)
    //Space Complexity O(1)
    bool hasCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        
        if(head == NULL || head->next == NULL){
            return false;
        }
        
        while(fast->next != NULL && fast->next->next != NULL){
            slow = slow -> next;
            fast = fast ->next -> next;
            if(slow==fast){
                return true;
            }
        }
        return false;
    }
};