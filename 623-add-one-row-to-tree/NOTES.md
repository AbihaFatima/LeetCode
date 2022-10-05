We can do a simple Tree Traversal (DFS, in this case) and just insert the nodes with v value at given depth d.<br>
​
The condition when d == 1 needs to be handled separately, since in this case, we are changing the root itself.
In all other cases, we will check if the children of current root are at depth d and if they are, we will add new node with value v as the new children of current node and the original children become the new children of node with value v. <br>
Time Complexity : O(N), where N is the number of nodes in the given tree.<br>
Space Complexity : O(N), where N is the number of nodes in the given tree. The worst case occurs in case of skewed tree where the recursion stack depth can reach N.