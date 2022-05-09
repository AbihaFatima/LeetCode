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
        ListNode *C = head;
        ListNode *P = NULL;
        ListNode *N;
        
        while(C!=NULL){
            N = C->next;
            C->next = P;
            P = C;
            C = N;
        }
        head = P;
        return head;
        
        // //Recursive Approach
        // if(head->next==NULL || head==NULL){
        //     return head;
        // }
        // ListNode* smallhead = reverseList(head->next);
        // ListNode* C = head;
        // C->next->next = C;
        // C->next = NULL;
        // return smallhead;
    }
};