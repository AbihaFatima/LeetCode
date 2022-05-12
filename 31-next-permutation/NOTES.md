**lexicographically greater**: Lexicographically means in dictionary order,i.e.if two strings are compared based on dictionary position the string which comes afterwards is said to be Lexicographically greater.<br>
so example arr[1, 2, 3] -> [1,3,2] i.e. just next greater array<br>
arr[2,3,1] -> [3,1,2]<br>
Now arr[3,2,1] -> [1,2,3] because 3,2,1 doesnot have next greater permutation so we will return the array in ascending order.<br>
Brute-force approach: https://takeuforward.org/data-structure/next_permutation-find-next-lexicographically-greater-permutation/ <br>
<br>**Optimised Approach:**
1. Linearly traverse given array from the end and find a number that is greater than its adjacent `nums[i] > nums[i-1]`. Store the index of smaller number in breakPoint variable. If there is no such element, reverse entire array and return.<br>
2. Linearly traverse from the end and this time find a number larger than `nums[breakPoint]`. Let's call it `nums[i]`.<br>
3. Swap `nums[i]` and `nums[breakPoint]`.<br>
4. Reverse the array from index `breakPoint + 1` to `nums.size()`.<br>

**Example:**<br>
- Consider nums[] = [1, 3, 5, 4, 2].
- Traverse from back and find a breakpoint. Here, index `breakPoint = 1` and `nums[breakPoint] = 3`
- Traverse from back and find a number larger than this. Here this number is: nums[i] = 4
- Swap `nums[breakPoint]` and `nums[i]`. Value after swapping: nums[] = [1, 4, 5, 3, 2].
- Reverse array from `breakPoint + 1` to `nums.size()` i.e. these elements: [1, 4, 5, 3, 2]
- Final answer = [1, 4, 2, 3, 5].
