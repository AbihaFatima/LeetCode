/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
/*
TimeComplexity : O(N); although recursive solution does take some space(recursive stack)
1. Base case: if the root is null than return null
2. connect the left subtree of same level with right subtree of that same level 
3. connect the rightmost node of a level to the leftmost node of the next level.
4. Now just repeat the steps over and over for every level of tree (recursive calls for left and right subtrees.)


*/
class Solution {
public:
    Node* connect(Node* root) {
        if(root==NULL){
            return NULL;
        }
        if(root->left != NULL) root->left->next = root->right;
        if(root->right != NULL && root->next != NULL) root->right->next = root->next->left;
        connect(root->left);
        connect(root->right);
        return root;
    }
};