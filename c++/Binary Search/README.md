# Binary search
> Input file: stdin <br/>
Output file: stdout <br/>
Time limit: 1 sec <br/>
Memory limit: 256 mb

Implement the binary search algorithm.

**Input**

The first line contains the numbers $n$ and $k$ $(1\le n,k \le 10^5)$.

The second line contains $n$ elements of the first array sorted in ascending order, and the third line — $k$ elements of the second array. The elements of the arrays — integers with absolute values not exceeding $10^9$.

**Output**

For each of the $k$ numbers in the second array, print on a separate line «YES» if that number occurs in the first array, and «NO» otherwise.

**Examples**
---
**Input 1:**
```
10 5
1 2 3 4 5 6 7 8 9 10
-2 0 4 9 12
```

**Output 1:**
```
NO
NO
YES
YES
NO
```