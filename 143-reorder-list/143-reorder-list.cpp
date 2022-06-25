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
/*
Brute-Force: (Recursively finding the penumilate (2nd Last) node and linking to head node) for each node. so here TC: O(N^2)

Two-Pointer Approach: (Most Optimised Approach)
TC:O(N)
SC:O(1)
    Intuition:
    - Find the middle node of the LL
    - Reverse the LL from middle->next node
    - Merge the two halfs accordingly
*/
class Solution {
public:
    ListNode* getMiddle(ListNode* head){
        if(!head) return NULL;
        ListNode *slow=head, *fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    
    ListNode *reverseList(ListNode* head){
        ListNode *curr = head;
        ListNode *prev = NULL;
        ListNode *nextNode;
        while(curr!=NULL){
            nextNode = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextNode;
        }
        return prev;
    }
    void reorderList(ListNode* head) {
        //Base Case if LL has zero,one or two nodes
        if(head==NULL || head->next==NULL || head->next->next==NULL) return;
        
        ListNode *mid = getMiddle(head);
        
        ListNode *revMid = reverseList(mid->next);
        mid->next = NULL;
        
        //Merging the two halfs
        while(head!=NULL && revMid!=NULL){
            ListNode *temp = head->next;
            head->next = revMid;
            revMid = revMid->next;
            head->next->next = temp;
            head = temp;
        }
        
    }
};