<h2>974. Subarray Sums Divisible by K</h2><h3>Medium</h3><hr><div><p>Given an integer array <code>nums</code> and an integer <code>k</code>, return <em>the number of non-empty <strong>subarrays</strong> that have a sum divisible by </em><code>k</code>.</p>

<p>A <strong>subarray</strong> is a <strong>contiguous</strong> part of an array.</p>

<p>&nbsp;</p>
<p><strong>Example 1:</strong></p>

<pre><strong>Input:</strong> nums = [4,5,0,-2,-3,1], k = 5
<strong>Output:</strong> 7
<strong>Explanation:</strong> There are 7 subarrays with a sum divisible by k = 5:
[4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
</pre>

<p><strong>Example 2:</strong></p>

<pre><strong>Input:</strong> nums = [5], k = 9
<strong>Output:</strong> 0
</pre>

<p>&nbsp;</p>
<p><strong>Constraints:</strong></p>

<ul>
	<li><code>1 &lt;= nums.length &lt;= 3 * 10<sup>4</sup></code></li>
	<li><code>-10<sup>4</sup> &lt;= nums[i] &lt;= 10<sup>4</sup></code></li>
	<li><code>2 &lt;= k &lt;= 10<sup>4</sup></code></li>
</ul>
</div>
<hr>
<div>
	<p>
<strong>Hash Table Approach</strong><br>
The time complexity can be further if we use a hash table to store intermediate results. The time complexity is O(n), and the space complexity is O(k).

We loop through the array and use an accu_sum variable to store the accumulative sum. During the iteration, we calculate the modulo (accu_sum % k). We then store the modulo to a hash table as a key and the number of occurrence of this modulo as the value.

During the iteration, if we have already found an accu_sum that has the same modulo with k as the current accu_sum, then the subarray between these two accu_sum has a sum divisible by k.

We can check how many same modulo has occurred before, that will be the number of subarrays whose sums are divisible by k. Thus, we can add the value of this modulo in the hash table to the total count.

Here is a complete walk through of the hash table approach. The array nums is {4,5,0,-2,-3,1}, and k is 5.
```cpp		
|             nums            | accu_sum | modulo | ht
| 4  | 5  | 0  | -2 | -3 | 1  |     -    |    -   | (0,1)       <-- count = 0
  i                           |     4    |    4   | (0,1) (4,1) <-- No such subarray found
       i                      |     9    |    4   | (0,1) (4,2) <-- The sum of subarray [1..1] is divisible by k
                                                                    count = count+ht[modulo]-1 = 0+1 = 1
            i                 |     9    |    4   | (0,1) (4,3) <-- The sum of subarray [1..2], [2..2] is divisible by k
                                                                    count = count+ht[modulo]-1 = 1+2 = 3
                 i            |     7    |    2   | (0,1) (4,3) (2,1) <-- No such subarray found
                      i       |     4    |    4   | (0,1) (4,4) (2,1) <-- The sum of subarray [1..4] [2..4] [3..4] is divisible by k 
                                                                          count = count+ht[modulo]-1 = 3+3 = 6
                           i  |     5    |    0   | (0,2) (4,4) (2,1) <-- The sum of subarray [0..5] is divisible by k
                                                                          count = count+ht[modulo]-1 = 6+1 = 7 
```
</p>
</div>
