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
    //Time Complexity is O(N) + O(N - N%K) ~= approx O(N) linear time
    //Space Complexity is O(1)
    
//     ListNode* rotateRight(ListNode* head, int k) {
//         //Base or Edge Cases:
//         if(head==NULL || head->next == NULL || k==0){
//             return head;
//         }
//         int len = 1;
//         ListNode *curr = head;
        
//         while(curr->next!=NULL && len++){
//             curr = curr->next;
//         }
        
//         curr->next = head; //as while computing length we reached end of LL and so now we have to point it to head (Circular LL)
//         k = k % len;//As the multiple of k would return same LL
        
//         k = len - k;
//         //go till the (len-k)th node
//         while(k!=0){
//             curr = curr->next;
//             k--;
//         }
//         //now point the next of curr to head
//         head = curr->next;
//         //Then point it to NULL as (len-k)th node is the last node
//         curr ->next = NULL;
        
//         return head;
//     }
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || head==NULL || head->next==NULL){
            return head;
        }
        int len = 1;
        ListNode *curr = head;
        while(curr->next!=NULL && len++){
            curr = curr->next;
        }
        //Curr will be pointing to the end node;
        curr->next = head;
        k = k % len;
        k = len - k;
        while(k!=0){
            curr = curr->next;
            k--;
        }
        head = curr->next;
        curr->next = NULL;
        return head;
    }
    
};