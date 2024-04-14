/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

//TC: O(N) SC:O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *dummy = new Node(INT_MAX);
        Node *runner = dummy, *curr=head;
        unordered_map<Node* , Node*>mp; //to map random pointers to curr node
        
        //Iterate by creating base list and also storing nodes in map
        while(curr!=NULL){
            Node *newNode = new Node(curr->val);
            runner->next = newNode;
            mp[curr] = newNode;
            curr = curr->next;
            runner = runner->next;
        }
        runner = dummy->next;
        curr = head;
        //Now connect the nodes to their random pointers
        while(curr!=NULL){
            if(curr->random){
                runner->random = mp[curr->random];
            }
            curr = curr->next;
            runner = runner->next;
        }
        return dummy->next;
    }
};