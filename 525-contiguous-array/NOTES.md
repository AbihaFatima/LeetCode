1. Brute force approach:
* We start at i = 0 & traverse till the last index using loop 1 & loop 2 traverses from i & traverses till the last index.
*  We consider every possible subarray within the given array and count the number of zeros and ones in each subarray.
* Each time, the no. of zeroes & ones becomes equal we update the maxLength.
* Time Complexity : O(N^2)
* Space Complexity : O(1)
2.  Optimised approach using hashmap:
* if one comes increment sum and if zero comes decrement sum
* the map will have sum and indices as key value pair
* if sum==0 store the update longest subarray and store sum and its index in hashmap
* Self explanatory code