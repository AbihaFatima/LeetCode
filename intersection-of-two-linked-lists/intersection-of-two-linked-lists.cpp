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
    //Hashing can also be done : by storing  the address and checking the address in the hash table and returning if the address is repeated in the hashtable
    //Time Complexity O(2M) M is length of longer linked list
    //Space Complecity is O(1)
    
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *a = headA;
        ListNode *b = headB;
        //If a and b have different length we will stop the iteration after 2nd iteration
        
        while(a!=b){
            //For the first iteration we will reset the pointer to the head of another linked list
            a = a==NULL ? headB : a->next;
            b = b==NULL ? headA : b->next;
        }
        return a;
    }
};