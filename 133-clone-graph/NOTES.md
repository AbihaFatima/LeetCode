Approach:
Video Tutorial - By Tech Dose<br>
[Another yt Tutorial](https://www.youtube.com/watch?v=jWf5F_shzho)<br>
- we are having a visited array of Node* datatype where we are initially storing  it as NULL and while traversing we will be storing whole node in the array.<br>
- We are doing DFS traversal with a little modification<br>
- we will first start with the copy node and remove Null marker by pushing its val to vis array and also its neighbor array. because we need new neighbor array for every node.
after doing DFS we will return the copy node.<br>