/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    //Time Complexity is O(N)
    //Space complexity is O(1)
//     ListNode *detectCycle(ListNode *head) {
//         if (head == NULL || head->next == NULL)
//             return NULL;
//         ListNode *slow = head;
//         ListNode *fast = head;
//         ListNode *temp = head;
        
//         //Find the collision point
//         while(fast->next != NULL && fast->next->next != NULL){
//             slow = slow->next;
//             fast = fast->next->next;
//             if(slow==fast){ //Cycle exists
//                 while(slow != temp){ //entry(temp) location found
//                     slow = slow->next;
//                     temp = temp->next;
//                 }
//                 return temp;
//             }
//         }
//         return NULL;
//     }
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *temp = head;
        
        //Find Collision point
        while(fast!=NULL && fast->next!=NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow==fast){
                //LL cycle exists
                //Finding the collision location
                while(slow!=temp){
                    slow = slow->next;
                    temp = temp->next;
                }
                return temp;
            }
        }
        return NULL;
    }
};