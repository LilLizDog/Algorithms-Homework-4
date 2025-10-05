We are given an array a where $a_i$ is the i'th distance.

What path will get us the lowest maximum height and leave us at
height=0 by the n'th jump? 

The recursive decomposition for this is 

$opt(i,y)=min(opt(i-1, y-a_i), opt(i-1, y+a_i), y)$

We can turn this into a table easily since y is at most 1000,
and i is at most 40.

With tabulation however, it sounds difficult to reconstruct the up-down sequence
because from one position to the next, the value in the table isn't always
increasing or always decreasing, since instead we keep a running max. 
Maybe this isn't so hard.

So from a bottom up approach, we would just iterate i=0 to n, and h=0 to 1000,
then do opt[i][h] = min(opt[i-1][h-a_i], opt[i-1][h+a_i], h). Then opt[n-1][0]
is the minimum height of the best workout routine for peter parker. But of course
we have to reconstruct the sequence. In addition, there are just a ton of heights
for every i that just can't be reached. Presumably we fill in our table initially
with like 9999 to track unreachable positions. But this is a waste of computing time.

Instead we keep a set of all positions we can reach at distance i. Then for distance i+1,
we create a new set, just adding and subtracting d_{i+1} to each distance in the current set.
Here we easily identity the overlapping subproblems in height. To choose the best height,
we just pick the one that has the lower max height (current height included in max height).
In addition, we can eliminate heights less than 0. And with this approach, keeping track
of the sequence is trivial, as we can just have a lookup structure.