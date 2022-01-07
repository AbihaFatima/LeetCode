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
    //SpaceComplexity : O(1)
    /*
    The constraint given is from -2^31 to 2^31-1, and INT_MAX = 2^31-1 and INT_MIN = -2^31.
    so INT_MIN and INT_MAX won't work here, instead use LONG_MIN and LONG_MAX
    */
    bool isValidBST(TreeNode* root) {
        return validBST(root,LONG_MIN,LONG_MAX);
    }
    bool validBST(TreeNode* root,long minVal, long maxVal){
        if(root == NULL) return true;
        if(root->val <= minVal || root->val >= maxVal) return false;
        return validBST(root->left, minVal , root->val) && validBST(root->right, root->val,maxVal);
    }
};