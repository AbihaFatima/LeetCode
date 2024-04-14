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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL or head->next==NULL) return head;
        ListNode *odd=head, *even=head->next, *evenHead=head->next;
        while(odd->next and even->next){
            odd->next = even->next;
            even->next = odd->next->next;
            odd = odd->next;
            even = even->next;
        } 
        odd->next = evenHead; //Connecting first even node to end of odd list
        return head;
    }
};