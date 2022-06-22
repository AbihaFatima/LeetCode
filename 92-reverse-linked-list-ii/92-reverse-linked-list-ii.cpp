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
    ListNode* reverseList(ListNode* head) {
        ListNode *Curr = head;
        ListNode *Prev = NULL;
        ListNode *NextNode;
        
        while(Curr!=NULL){
            NextNode = Curr->next;
            Curr->next = Prev;
            Prev = Curr;
            Curr = NextNode;
        }
        head = Prev;
        return head;
    }
    /*
    1. Traverse till left and make a start node equal to curr
    4. traverse till right ;  as now curr would be at right index,make curr->next point to new node named remNode
    5. node remNode = curr->next and then curr->next = NULL
    6. make newHead node and pass reverse function(reversing linked list from start till right)
    if(prev is not nUll prev->next = newNode)
    7. we will traverse till right ->next = remainingNode
    */
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        int count = 1;
        ListNode *prev = NULL;
        ListNode *curr = head;
        while(count!=left){
            prev = curr;
            curr = curr->next;
            count++;
        }
        ListNode * start = curr;
        //Traverse to find right and then point right to NULL
        while(count!=right){
            curr = curr->next;
            count++;
        }
        ListNode *remNode = curr->next;
        curr->next = NULL;
        //Reverse
        ListNode *newHead = reverseList(start);
        if(prev!=NULL){
            prev->next = newHead;
        }
        curr = newHead;
        while(curr->next!=NULL){
            curr = curr->next;
        }
        curr->next = remNode;
        if(left==1){
            return newHead;
        }
        else{
            return head;
        }
        
    }
};