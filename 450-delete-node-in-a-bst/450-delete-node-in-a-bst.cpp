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

/*
The worst case time complexity would be O(h) where h is the height of the tree and if the tree is skewed then the time complexity would be O(n)
*/
class Solution {
private:
    TreeNode* helper(TreeNode* root){
        if(root->left == NULL){
            return root->right;
        }
        if(root->right == NULL){
            return root->left;
        }
        TreeNode *rightChild = root->right;
        TreeNode *lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == NULL) return root;
        return findLastRight(root->right);
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        TreeNode *temp = root;
        if(root==NULL) return NULL;
        if(root->val == key) return helper(root);
        
        while(root!=NULL){
            if(root->val > key){
                //We will traverse the left subtree
                if(root->left!=NULL && root->left->val == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root = root->left;
                }
            }
            else{
                //We will traverse the right subtree
                if(root->right!=NULL && root->right->val == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root = root->right;
                }
            }
        }
        return temp;
    }
};