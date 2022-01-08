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
    //Brute-Force Approach
    // TreeNode* bstFromPreorder(vector<int>& preorder) {
    //     int size = preorder.size();
    //     if(size == 0){
    //         return NULL;
    //     }
    //     TreeNode* root = new TreeNode(preorder[0]);
    //     if(size == 1){
    //         return root;
    //     }
    //     vector<int>left;
    //     vector<int>right;
    //     for(int i=1;i<size;i++){
    //         if(preorder[i]<preorder[0]){
    //             left.push_back(preorder[i]);
    //         }
    //         if(preorder[i]>preorder[0]){
    //             right.push_back(preorder[i]);
    //         }
    //     }
    //     root->left = bstFromPreorder(left);
    //     root->right = bstFromPreorder(right);
    //     return root;
    // }
    
    //Better Approach without auxilary space
    //TimeComplexity : O(N)
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return bst(preorder, index, INT_MIN, INT_MAX);
    }
    TreeNode* bst(vector<int>& preorder, int &index,int min, int max){ 
        
        if (index>=preorder.size()) return NULL;
        
        int val = preorder[index];
        if(val>max || val<min) return NULL;
        ++index;
        
        TreeNode* root = new TreeNode(val);
        root->left = bst(preorder,index,min,val);
        root->right = bst(preorder,index,val,max);
        
        return root;
    }
};