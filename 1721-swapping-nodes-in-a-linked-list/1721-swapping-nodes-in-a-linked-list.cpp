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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *firstK = head;
        ListNode *lastK = head;
        int len=0,i=1;
        
        //Finding first Kth node
        for(firstK=head;i<k;i++){
            firstK = firstK->next;
        }
        
        i=1;
        //Finding last Kth node
        while(lastK!=NULL){
            lastK = lastK->next;
            len++;
        }
        for(lastK=head;i<len-k+1;i++){
            lastK=lastK->next;
        }
        
        //Swapping the vals of both nodes
        int temp = firstK->val;
        firstK->val = lastK->val;
        lastK->val = temp;
        return head;
        
    }
};