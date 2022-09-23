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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        //Brute force Approach time complexity - O(N1 + N2)
                            // Space Complecity - O(N1+N2)
//         //Check if List1 is empty then return L2
//         if(l1 == NULL){
//             return l2;
//         }
//          //Check if List2 is empty then return L1
//         else if(l2 == NULL){
//             return l1;
//         }
        
//         //Creating List3 to store sorted elements of List1 and List2
//         ListNode* l3;
//         if(l1->val < l2->val){
//             l3=l1;
//             l3->next = mergeTwoLists(l1->next, l2);
//         }
        
//         else{
//             l3=l2;
//             l3->next = mergeTwoLists(l1,l2->next);
//         }
        
//         return l3;
        
        
//Optimised solution in place that is time complexity will be O(N1+N2) but space complexity will be O(1)
//         if(l1 == NULL) return l2;
//         if(l2 == NULL) return l1;
//         if(l1->val > l2->val) std::swap(l1,l2);
        
//         ListNode *res = l1;
//         while(l1!=NULL && l2!=NULL){
//             ListNode *temp = NULL;
//             if(l1!=NULL && l1->val <= l2->val){
//                 temp = l1;
//                 l1 = l1->next;
//             }
//             temp ->next =l2;
            
//             //swap 
//             std::swap(l1,l2);
            
//         }
//         return res;
        
//######################################################################################
        
        //RECURSIVE APPROACH
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;
        if(l1==NULL && l2==NULL) return NULL;
        
        if(l1->val <= l2->val){
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        }
        else{
            l2->next = mergeTwoLists(l1,l2->next);
            return l2;
        }
        
    }
};