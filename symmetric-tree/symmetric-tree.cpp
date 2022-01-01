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
    //SpaceComplexity : O(h); h is the height of the tree
    bool isMirror(TreeNode* n1, TreeNode* n2){
        if(n1==NULL && n2!=NULL) return false;
        if(n1!=NULL && n2==NULL) return false;
        if(n1==NULL && n2==NULL) return true;
        
        if(n1->val != n2->val) return false;
        
        return isMirror(n1->right,n2->left) && isMirror(n1->left,n2->right);

    }
    bool isSymmetric(TreeNode* root) {
        if(root == NULL) return true;
        return isMirror(root->left,root->right);
    }
};