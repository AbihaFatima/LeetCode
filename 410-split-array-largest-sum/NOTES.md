- the idea is that min max sum will lie in the range (max(nums[i]),sum(nums[i])) for(i=0 to n). <br>
- every time we find avg of this range and see how many intervals' sum exceed the avg. <br>
- if there are more than "m" intervals, then we need to increase the bar becoz many intervals are demanding to get separated. <br>
- if they are less than "m", then we need to lower the bar becoz very few intervals are willing to get separated. <br>
- we will keep doing this until if reach a postn when exactly "m" intervals will get separated.<br>
- at this point we will obvsly have lower bar=upper bar. <br>
- Time Complexity: O(N log(sum)) <br>
- Space Complexity: O(1)