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
For each node, the diameter is the height of the left node + the height of the right node.
So we use height function to get the heights recursively, and keep in diameter the maximum seen.

Time Complexity: O(n)
Space Complexity: O(n) - for the recursive calls.
*/
class Solution {
private:
    int diameter = 0;
public:
    int height(TreeNode *root){
        
        if(root==NULL){
            return 0;
        }
        
        int Left = height(root->left);
        int Right = height(root->right);
        diameter = max(diameter, Left+Right);
        
        return max(Left,Right) + 1;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return diameter;
    }
};