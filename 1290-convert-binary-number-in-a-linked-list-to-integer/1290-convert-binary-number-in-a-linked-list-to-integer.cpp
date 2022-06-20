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
Iterative Approach:
Time Complexity: O(N);
Space Complexity: O(1);
*/
class Solution {
public:
    int getDecimalValue(ListNode* head) {
        int decimal=0;
        while(head!=NULL){
            decimal = (decimal * 2) + head->val; 
            head=head->next;
        }
        return decimal;
    }
};