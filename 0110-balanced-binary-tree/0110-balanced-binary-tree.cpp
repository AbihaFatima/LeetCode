/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//TimeComplexity : O(N)
class Solution {
    int balance(TreeNode * node){
        if(!node){
            return 0;
        }
        
        int lh = balance(node->left);
        int rh = balance(node->right);
        
        if(lh == -1 || rh == -1) //if either of them is -1, we dont have to go further and just return -1
            return -1;
        
        if(abs(lh-rh) > 1)      //abs() gives us the absolute difference of the two heights 
            return -1;
        
        return max(lh,rh)+1;
    }
    
public:
    bool isBalanced(TreeNode* root) {
        //if the tree is balanced it`ll be positive(true) or else it`ll be definitely negative(false).
        if(balance(root) == -1) return false;
        return true;
    }
};