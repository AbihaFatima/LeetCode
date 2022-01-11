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
public:
class bst {
    public:
      bool isbst;
      int max;
      int min;
      int sum;
    };
        bst Bst(TreeNode* root) {

      if (root == nullptr)
      {  
        bst bres;            // Base Case
        bres.isbst = true;
        bres.max = INT_MIN;
        bres.min = INT_MAX;
        bres.sum = 0;
        return bres;
      }
      bst l = Bst(root->left); // left sub-tree
      bst r = Bst(root->right); // right sub-tree

      bst ans;

      ans.max = max(root->val, max(l.max, r.max));
      ans.min = min(root->val, min(l.min, r.min));

      // Check if current tree is Bst or not ?
      ans.isbst = l.isbst && r.isbst && (l.max < root->val && r.min > root->val);

      if(ans.isbst){
          ans.sum = l.sum + r.sum + root->val;
          ans.min = min(root->val, min(l.min, r.min));
          ans.max = max(root->val, max(l.max, r.max));
      }
      else
          ans.sum = max(l.sum, r.sum);
      
      res = max(res, ans.sum);
      return ans;
    }
    
    int res = INT_MIN;
    
    int maxSumBST(TreeNode* root) {
        Bst(root);
        return res > 0 ? res : 0;
    }
};