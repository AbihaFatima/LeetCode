First, count the number of 1 or 0 grouped consecutively.<br>
For example "0110001111" will be [1, 2, 3, 4].<br>
​
Second, for any possible substrings with 1 and 0 grouped consecutively, the number of valid substring will be the minimum number of 0 and 1.<br>
For example "0001111", will be min(3, 4) = 3, ("01", "0011", "000111")<br>
​