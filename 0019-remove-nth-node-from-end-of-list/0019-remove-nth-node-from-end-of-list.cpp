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
//Single pass solution using two pointers
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head, *slow = head;
        //Maintain a gap of n nodes between fast and slow
        while(n--) fast=fast->next;
        if(fast==NULL) return head->next;
        
        //Iterate 1 unit each until fast reaches end if list
        while(fast->next != NULL){
            slow=slow->next;
            fast=fast->next;
        }
        
        //Slow would be exactly at (n+1)th position from the end
        slow->next = slow->next->next; //skipping the end node
        return head;
    }
};