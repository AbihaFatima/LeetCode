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
private: 
    ListNode *reverseLL(ListNode * head){
        ListNode *curr = head;
        ListNode *prev=NULL, *temp=NULL;
        while(curr!=NULL){
            temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseLL(l1);
        l2 = reverseLL(l2);
        ListNode *head = new ListNode(-1);
        ListNode *curr=head;
        int carry=0;
        while(l1 or l2){
            int v1 = l1? l1->val: 0;
            int v2 = l2? l2->val: 0;
            int total = v1+v2+carry;
            carry = total/10;
            total = total%10;
            curr->next = new ListNode(total);
            curr=curr->next;
            l1 = l1? l1->next : l1;
            l2 = l2? l2->next : l2;
        }
        if(carry) curr->next = new ListNode(1);
        return reverseLL(head->next);
    }
};