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
    //Brute Force Approach: traversing and checking nodes
    
    //************************ HASHING **********************
    //Hashing can also be done : by storing  the address and checking the address in the hash table and returning if the address is repeated in the hashtable
    //TC: O(M+N)
    //SC: O(M)
    
    // ListNode *getIntersectionNode(ListNode *A, ListNode *B){
    //     unordered_map<ListNode*, int>mp;
    //     while(A!=NULL){
    //         mp[A]++;
    //         A=A->next;
    //     }
    //     while(B!=NULL){
    //         if(mp[B] > 0) return B;
    //         B=B->next;
    //     }
    //     return NULL;
    // }
    
//****************** LENGTH DIFFERENCE APPROACH *****************************
//TC: O(m+n)
//SC: O(1)
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB){
        ListNode *A = headA;
        ListNode *B = headB;
        int l1=0,l2=0;
        while(A!=NULL){
            l1++;
            A = A->next;
        }
        while(B!=NULL){
            l2++;
            B = B->next;
        }
        int diff = abs(l2-l1);
        if(l1>l2){
            while(diff){
                headA = headA->next;
                diff--;
            }
        }
        else{
            while(diff){
                headB = headB->next;
                diff--;
            }
        }
        while(headA!=NULL and headB!=NULL){
            if(headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return NULL;
    }
    
    
    
    //Time Complexity O(2M) M is length of longer linked list
    //Space Complecity is O(1)
    
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *a = headA;
//         ListNode *b = headB;
//         //If a and b have different length we will stop the iteration after 2nd iteration
        
//         while(a!=b){
//             //For the first iteration we will reset the pointer to the head of another linked list
//             a = a==NULL ? headB : a->next;
//             b = b==NULL ? headA : b->next;
//         }
//         return a;
//     }
};