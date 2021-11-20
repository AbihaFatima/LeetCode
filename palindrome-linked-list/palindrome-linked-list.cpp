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
    //Time Complexity : O(n/2) + O(n/2) + O(n/2)
    //Space Complexity : in place that is O(1)
    
    //Function to Reverse a LL [this happens after finding the middle of ll]
    ListNode *ReverseList(ListNode *head){
        ListNode *Prev = NULL;
        ListNode *N = NULL;
        
        while(head != NULL){
            N = head->next;
            head->next = Prev;
            Prev = head;
            head = N;
        }
        return Prev;
        
    }
    bool isPalindrome(ListNode* head) {
        //Base Case
        if(head==NULL || head->next == NULL){
            return true;
        }
        
        //So first find middle of LL
        ListNode *slow = head;
        ListNode *fast = head;
        while(fast->next!=NULL && fast->next->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //Slow pointer will be pointing to reversed 2nd half or reversed right half
        slow->next = ReverseList(slow->next);
        slow = slow->next;
        
        while(slow!=NULL){
            if(slow->val != head->val){
                return false;
            }
                slow = slow->next;
                head = head->next;
        }
        
        return true;
    }
};