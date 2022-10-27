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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return convert(nums,0,nums.size()-1);
    }
    TreeNode* convert(vector<int>& nums,int low, int high){
        while(low<=high){
            int mid = (low+high)/2;
            TreeNode* root = new TreeNode(nums[mid]);
            root->left = convert(nums,low,mid-1);
            root->right = convert(nums,mid+1,high);
            return root;
        }
        return NULL;
    }
};