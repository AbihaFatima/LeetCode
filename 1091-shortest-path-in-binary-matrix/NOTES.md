Intuition:<br>
It can be solved by bfs - time complexity. Both O(N * M)
<br>
One way, is to remember the distance from (0,0) to (n,m) inside the queue along with the indices as the third element. Ex: (0, 0, 1) and thus keep on adding 1s until you reach (n, m, shortestDistance) and return shortestDistance.
Because I'm doing it in-place, I don't need visited array.