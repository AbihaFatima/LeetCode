- Here we can observe a pattern to this problem.
```
a  e  i  o  u
n=1   1  1  1  1  1  /a, e, i, o, u
n=2   5  4  3  2  1  /a-> aa,ae,ai,ao,au | e-> ee,ei,eo,eu | i-> ii,io,iu | o-> oo,ou | u-> uu
n=3   15 10 6  3  1
```
- If we observe from last there will be only 1 element which will start with u. Every other element will have the count of previous count + next element count. As example
in n=2, i will be previous i(1) + count of next element, o(2) → 3
in n=3, e will be previous e(4) + count of next element, i(6) → 10<br>
​
<h5>Solution: </h5>
- Using 5 variables.
- Here we are adding previous value with the current next element with serial of a-e-i-o-u.
- Return by adding every element.
- Time complexity: O(n).