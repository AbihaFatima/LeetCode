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
    //TimeComplexity is O(1) and space complexity is also O(1)
    //A very simple Approach as we are not given the head node and deletion at tail is not posiible in the given questions constraints
    
    void deleteNode(ListNode* node) {
        //that is the value of given node will be replaced with next node
        node->val = node->next->val;
        
        //Now the change the pointer of replaced node to next of next node
        node->next = node->next->next;
    }
};