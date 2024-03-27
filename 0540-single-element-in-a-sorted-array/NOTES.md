Approach - Binary Search<br>
TC: O(logN)      SC: O(1)
<br>
- We can do binary search over the sorted array to find the single element. But on which condition we should move to left half or right half ? During binary search we always make move decision  based on mid value, here we do the same too but we consider both mid value and index and there are 4 possible cases: <br>
​
1. Mid Index Odd:
Means the length of array from start till mid value (included) is even. As the length of subarray [0, mid] is even the single element can be in [0, mid] or [mid+1, n-1]. Subarray [0, mid] length is even and if all elements in subarray are twice means no single element, then `nums[mid]` and `nums[mid-1]` will be same and single element will be in the right half [mid+1, n-1], so we move to right half. Otherwise `nums[mid]!=nums[mid-1]` and there is a single element in the left half [0, mid] and  so we move to left half. <br>
​
Example:<br>
[1,1,2,3,3,5,5] => mid = 3 => nums[mid]!=nums[mid-1] => nums[3]!=nums[2] =>move to left half <br>
[1,1,2,2,3,5,5] => mid = 3 => nums[mid]==nums[mid-1] => nums[3]==nums[2] => move to right half<br>
​
2. Mid Index Even:<br>
Means the length of array from start till mid value (included) is odd. As the length of subarray [0, mid] is odd the single element can be in [0, mid] or [mid+1, n-1]. Subarray [0, mid] length is odd and if nums[mid] and nums[mid+1] are same then the single element is in the right half, otherwise it is in the left half.
<br>
Example:<br>
- [1,1,3,2,2,4,4,5,5] => mid = 3 => nums[mid]!=nums[mid+1] => nums[3]!=nums[4] =>move to left half <br>
- [1,1,2,2,4,4,5,6,6] => mid = 3 => nums[mid]==nums[mid+1] => nums[3]==nums[4] =>move to right half <br>