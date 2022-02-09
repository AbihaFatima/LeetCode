1. Brute-force Approach :- using maps
- Time Complexity: O(N)
- Space Complexity : O(N)
<br>
2. Optimised Approach :- Two - Pointer Technique
- Time Complexity: O(N log N)  //Due to inbuilt sort function
- Space Complexity : O(1)
- We are aware of the fact that for a pair to be counted as an answer , both the elements ( x and x+k ) , need to be in the array.
- In this approach , first we sort the array and maintain 2 pointers.
- 1st Pointer --> 1st Element of the Pair
- 2nd Pointer --> 2nd Element of the Pair
- We set the 1st pointer at the 0th index and 2nd pointer at the 1st index. Then , Move the 2nd pointer until 2nd pointer - 1st pointer >=k .
- If the 2nd pointer - 1st pointer ==k , then increment the answer and move the 2nd pointer to the next greater element.
- Move the 1st pointer to the next greater element.
- Follow the above procedure until the 2nd pointer reaches the end of the array.