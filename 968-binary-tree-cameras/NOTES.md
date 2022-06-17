- Approach: We start installing cameras from the bottom and go back to the root node of the tree. Heren, we are going to use couple of variables 0, 1, 2 on nodes, where:<br>
- 0 -> This node needs camera to be installed (0 Cam monitor it)<br>
- 1 -> This node doesn't want camera (1 Cam monitor it)<br>
- 2 -> camera is already installed here (Cam fix here which monitor parent node and child nodes)<br>
​
The intuition is we will reach to the leaf nodes of the tree and start installing camera to the parent of the leaf node so that it can cover max 2 leaf nodes.<br>
[Credits](https://leetcode.com/problems/binary-tree-cameras/discuss/2161571/C%2B%2B-or-Use-DFS-or-Simple-and-Efficient-Solution-or-DLC-June-Day-17)