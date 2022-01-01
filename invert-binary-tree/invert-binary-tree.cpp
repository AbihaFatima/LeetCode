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
class Solution {
public:
    //TimeComplexity : O(N)
    //SpaceComplexity : O(1) but if considering the recursive stack O(h) where h is the height of the tree
    TreeNode* invertTree(TreeNode* root) {
        //Base Case
        if(root==NULL){
            return NULL;
        }
        
        //Recursive calls in left and right subtrees
        invertTree(root->left);
        invertTree(root->right);
        
        //Swap left and right nodes
        struct TreeNode* temp;
        temp = root->left;
        root->left = root->right;
        root->right = temp;
        
        return root;
    }
};