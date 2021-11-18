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
    //TimeComplexity O(n)
    //Space Complexity O(1)
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *start = new ListNode();
        start->next = head;
        ListNode *fast = start;
        ListNode *slow = start;
        
        for(int i=0;i<n;i++){
            fast = fast->next; //Moving fast pointer to nth node
        }
        while(fast->next != NULL){//Then moving both pointer by one step till fast->next is not null
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;//Delete the link by changing where the slow pointer points to
        
        return start->next;//This will be the new head of the linked list
    }
};