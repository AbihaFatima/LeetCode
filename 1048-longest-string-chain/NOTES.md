<strong>Time Complexity : O(n*n), Space Complexity : O(n)</strong><br>
​
- At first the array is `sorted according to length of the words`, so that another word after a word can not be its predecessor.<br>
​
- A `dp array` is declared for storing the maximum number of predecessor present in the array for a word in the array words.<br>
​
- An iterative dp is run for each element (`curr`). In it for each curr a loop is run from start of the array to the curr element (`prev`) where it checks if `prev is the predecessor of curr` using function predecessor() and stores the `maximun of dp[curr] and 1+dp[prev]`. Max is stored because there can be `multiple predecessor of curr before it`.<br>
​
- The ans is updated as `max of ans and dp[curr]` after each loop so that it store the longest word chain of predecessor and is returned at the end.<br>