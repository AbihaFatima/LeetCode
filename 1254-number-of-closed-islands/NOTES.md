Approach-<br>
- we call dfs on zeros and mark all the the zeros with -1 and also which are 4-directionally connected to those zeroes.<br>
- note my point here, that is if zeros are 4-directionally surrounded by 1 then it will not change to -1. so to make it clear, only boundary zeroes and its connected zeroes are changed to -1.
- so the matrix will now contain only isolated zeroes (that is zeroes surronded/enclosed by 1's)
- now we initialize ans=0, and perform dfs again, increment ans for that 0 and return the answer :)<br>
Summary :- We apply dfs on boundary and mark all boundary Os and its connected components as -1(to recognize they are visited). Now,the matrix consists of only those Os that are surrounded by water.So, we perform dfs on the matrix and find the number of connected components.