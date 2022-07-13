/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int ans=0;
    public void findNum(TreeNode root, int temp){
        if(root==null) return;
        temp = temp*10 + root.val;
        if(root.left==null && root.right==null){
            ans += temp;
        }
        findNum(root.left,temp);
        findNum(root.right,temp);
    }
    public int sumNumbers(TreeNode root) {
        if(root==null) return 0;
        findNum(root,0);
        return ans;
    }
}