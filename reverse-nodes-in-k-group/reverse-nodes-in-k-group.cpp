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
    //Time Complexity O(n)
    //Space Complexity O(1)
    ListNode* reverseKGroup(ListNode* head, int k) {
        //Base Case
        if(head==NULL || k==1){
            return head;
        }
        ListNode *dummy = new ListNode(0);
        dummy->next =head;
        
        ListNode *prev, *nex, *curr;
        prev = dummy;
        nex = dummy;
        curr = dummy;
        
        //Calculate the Length of LL
        int count = 0;
        while(head!=NULL){
            head= head->next;
            count++;
        }
        
        //for reversing k groups
        while(count>=k){
            curr = prev->next; //now pointing to head
            nex = curr->next; //next node of head
            
            for(int i=1;i<k;i++){
                curr->next = nex->next; //breaking the links of curr and nex and making nex point to curr and curr pointing to nex->next
                
                nex->next = prev->next; //breaking the link between nex and nex->next
                prev->next = nex; //prev which was assigned to dummy is now pointing to nex 
                nex = curr->next; //Moving nex forward with one step
            }
            count-=k; //reducing the count k times 
            prev = curr;
            //At this point the complexity becomes O(n) = O(n/k * k)
        }
        return dummy->next;
    }
};