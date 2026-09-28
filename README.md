# DSA Assignment - K-Way Merge

## Aim

To implement and compare 3-way K-way merging using a Min Heap and pairwise merging.

## Input

L1 = 10, 30, 50, 70

L2 = 20, 40, 60, 80

L3 = 15, 35, 55, 75

## K-Way Merge Using Min Heap

The first element of each sorted list is inserted into a Min Heap.
The minimum element is repeatedly removed and added to the output.
The next element from the same list is then inserted into the heap.

## Min Heap Output

10 15 20 30 35 40 50 55 60 70 75 80

## Pairwise Merge

First, L1 and L2 are merged.

10 20 30 40 50 60 70 80

The result is then merged with L3.

10 15 20 30 35 40 50 55 60 70 75 80

## Comparison

Min Heap comparisons = 21

Pairwise comparisons = 18

## Complexity

K-way Min Heap:
Time = O(N log K)
Space = O(K)

Pairwise Merge:
Time = O(NK)
Space = O(N)

## Conclusion

Both methods produce the same sorted output. The Min Heap method is more suitable when the number of sorted lists becomes large because it efficiently manages the smallest current element from each list.
