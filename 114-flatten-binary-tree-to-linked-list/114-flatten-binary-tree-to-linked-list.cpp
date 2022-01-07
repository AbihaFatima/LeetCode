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
//SpaceComplexity : O(N)
class Solution {
private :
    TreeNode* head = nullptr;
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        flatten(root->right); 
        flatten(root->left);
        
        root->left = nullptr;
        root->right = head;
        head = root;
    }
};