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

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return NULL;
        Node *temp = head;
        //First Pass creating a temp list pointing to its duplicate nodes
        while(temp != NULL){
            Node *newNode = new Node(temp->val);
            
            //create A -> A' -> B -> B' -> C -> C'
            newNode->next = temp->next;
            temp->next = newNode;
            temp = newNode->next;
        }
        temp = head;
        //2nd Pass: linking random pointers of original node to their duplicate nodes
        while(temp!=NULL){
            temp->next->random = (temp->random)? (temp->random->next) : NULL;
            temp = temp->next->next;
        }
        //3rd pass: seperating the original and cloned list, pointing res to head of cloned list and returning res
        Node *original = head;
        Node *clone = head->next;
        Node *res = head->next;
        
        while(original!=NULL){
            original->next = original->next->next;
            clone->next = (clone->next)?clone->next->next : NULL; //when clone node is last, it has to be pointed to null
            original = original->next;
            clone = clone->next;
        }
        return res;
    }
};