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
    //SpaceComplexity : O(N)
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()!=postorder.size()){
            return NULL;
        }
        //Map for hashing the values of the inorder traversal vector
        map<int,int> inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]] = i;
        }
        
        TreeNode* root = getTree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,inMap);
        
        return root;
    }
    
    TreeNode* getTree(vector<int>& inorder, int inStart, int inEnd, vector<int>& postorder, int postStart, int postEnd, map<int,int>& inMap){
        //BaseCase
        if(postStart>postEnd || inStart>inEnd){
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[postEnd]);
        
        //Index of root in inorder array
        int inRoot = inMap[root->val];
        
        //End of Index of left inorder Array
        int numsLeft = inRoot - inStart;
        
        root->left = getTree(inorder,inStart,inRoot-1,postorder,postStart,postStart+numsLeft-1,inMap); 
        
        root->right = getTree(inorder,inRoot+1,inEnd,postorder,postStart+numsLeft,postEnd-1,inMap); 
        return root;
    }
};