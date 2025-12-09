# Cows to the stalls
> Input file: stdin <br/>
Output file: stdout <br/>
Time limit: 1 sec <br/>
Memory limit: 256 mb

On the straight line there are stalls in which you have to arrange the cows so that the minimum distance between the cows is as large as possible.

**Input**

The first line contains $N$ $2<N≤105$ – the number of stalls and $K$ $1<K<N$ – the number of cows. The second line contains N natural numbers in ascending order – the coordinates of the stalls (the coordinates do not exceed $10^9$).

**Output**

One number – the largest possible allowable distance.

**Examples**
---
**Input 1:**
```
6 3
2 5 7 11 15 20
```

**Output 1:**
```
9
```
---
**Input 2:**
```
5 3
1 2 3 100 1000
```

**Output 2:**
```
99
```
---