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
TC: O(N)
SC: O(1)
Approach:
- Make two linked list having head value as 0
- One LL for values less than x and another LL for values greater than and equal to x
- start traversing the main LL, for every node check the value of node is less than given x,
- if it's less than x then point the next node of l1 to that node
- else if its val greater than current node, then point the next node of l2 to that node
- at the end, as l1 will be pointing to end of l1, so after loop point l1->next to list 2
- and list2->next to NULL
- Now final answer would be list1->next as list1 was initialized with 0 val in head node.
*/
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *list1 = new ListNode(0);
        ListNode *list2 = new ListNode(0);
        ListNode *l1=list1;
        ListNode *l2=list2;
        while(head){
            if(head->val < x){
                l1->next = head;
                l1 = l1->next;
            }
            else{
                l2->next = head;
                l2 = l2->next;
            }
            head = head->next;
        }
        
        l1->next = list2->next;
        l2->next = NULL;
        
        return list1->next;
    }
};