we discuss two possible solutions for this problem
# Binary Search Solution
Following a naive appraoch first, we can think of looping through all possible k's and check for each k if it is valid.
to check if a given k is valid we have to test that all consecutive k elements sum up to at least S.
to do that in an efficient way we can either:
- precalculate a prefix sum array for the given array of coins B, then simply check that each segment of size k sum up to at least S.
- follow a two pointers approach: start by calculating the sum of the first k elements of the array and store it in a variable sum,
	say elements from 1 to k, then loop through k + 1 to n and each iteration add b[i] to sum and substract B[i - k] from sum.
	that way in each iteration you have the sum of elements from i - k + 1 to i, and check if that sum is always greater than of equal to S.


So far we can test if a given k is valid in O(n), so looping through all possible k's and checking if each k is valid until we found the answer
would have a time complexity of O(n^2) and that's not enough. Fortunately, we can improve our alogorithm to run in O(n log n):
let i be an integer, 1 <= i <= n, if i is valid (every i consecutive elements sum up to at least S), we know then that k (the answer we're searching for)
must be <= i.
Conversely if i is not valid, the answer k must be > i.
Therefore we can use binary search to search for k: define l = 1 and r = n, check if (l + r) / 2 is valid, if it is the case then r = (l + r) / 2,
else l = (l + r) / 2 + 1.

time complexity of this solution is O(n log n)

# Two Pointers Solution

We can find an even better solution using two pointers l and r.
start with l = 1 and r = 1, then while the sum of elements from l to r < S, keep incrementing r.<br>
We have now a range of elements from l to r that add up to at least S. <br>
We loop now until r > n:
1. if sum of elements between l and r (inclusive) >= S then simply shift the range to the right by 1 (increment l and r by 1)
2. otherwise the sum of elements between l and r < S, then decrement l by 1 (l--) thus expanding the range by one, we are sure that we have 
	to decrement l only by one because we know from the previous step that the sum of elements from (l - 1) to (r - 1) is already greater than or equal 
	to S.

When the loop exists (r > n) the result is the number of elements between l and r, that is r - l + 1.

time complexity of this solution is O(n)

