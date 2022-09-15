Intuition:<br>
Since we need to return an original array if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order, so we first sort the array.<bt>
Since we have sorted the array, so we will find the twice of a number, If we get it, well and good, check further, else return {}<br>
​
Approach:<br>
First we take a map, then we sort the given array changed.
We keep removing the smallest element n and 2 * n and keep putting n into the answer until changed array becomes empty.
If at anytime the we are unable to remove elements we return empty array.
<br>
Time Complexity: O(NLogN)
Space Complexity: O(N)