Approach<br>
- First calculate prefix sums array for the given array nums.<br>
- Now, your task is to find sum of elements from left to right.<br>
- If `left == 0`, means we need to directly return sum at the index `pref[right]`.<br>
- Otherwise, just return the difference of sums at `pref[right] - pref[left - 1]`.<br>
- Example for dry run given in cpp file.