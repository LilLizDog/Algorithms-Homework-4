The question is what is the longest nondecreasing sequence of trains
we can make by the n'th train.

The subproblem is what is the longest nondecreasing sequence of trains
we can make by the (n-1)'th train.

Well, we are doing more than just "add a or don't add a", we are doing
"add a to beginning, back, or don't". Obviously our subproblems overlap
on more than just i'th train, otherwise it would just be a greedy approach.

Suppose we start at some pivot within the array. Then we can turn this into 2
DP problems where we're finding the longest nondecreasing sequence of trains > pivot after the pivot,
and the longest nonincreasing sequence of trains < pivot after the pivot; one for the trains that 
all go after the pivot, and one for the trains that all go behind the pivot in the final outcome.

Then we can just use every train as a pivot and pick the max sum of the two.

The problem for monotonic subsequence is "whats the longest monotonic subsequence 
we can make by the n'th train".

The subproblem is what is the longest monotonic subsequence we can make by the i'th train.

At each train i, there are various amounts of subsequences that can be made from the
first i-1 trains that all the have the same length. These are our overlapping subproblems.
Suppose for monotonicity we are looking for a nondecreasing subsequence. In this case,
among all sequences of the same lengths, we only keep the one with the lowest max weight,
or the lowest end element. 
Thus this is the bottom up approach with respect to generating new monotonic subsequences
from prior subsequences.

An easier way of thinking about things is at train i, if train j is less than i and j is the terminal of
a nondecreasing subsequence, i can safely be added to that sequence. For every train i, we can iterate through
every train j before it, take the max, and add 1. However, in debugging I found that in doing this for both 
a nondecreasing subsequence and nonincreasing subsequence then taking the max pair, this would actually generate the pivots backwards. So actually you have to iterate through every train j backwards.