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
class mycompare{
    public:
    bool operator()(ListNode *x,ListNode *y){
        return (x->val>y->val);
    }
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>,mycompare>pq;
        for(int i=0;i<lists.size();i++){
            if(lists[i]!=NULL)
             pq.push(lists[i]);
        }
        ListNode *head=new ListNode();
        ListNode *temp=head;
        while(!pq.empty()){
            ListNode *top=pq.top();
            pq.pop();
            temp->next=top;
            temp=temp->next;
            if(top->next)
                pq.push(top->next);
        }
           
        return head->next;
    }
};