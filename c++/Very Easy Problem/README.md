# Cows to the stalls
> Input file: stdin <br/>
Output file: stdout <br/>
Time limit: 1 sec <br/>
Memory limit: 256 mb

This morning, the jury decided to add one more, Very Easy Problem, to the Olympiad. The secretary of the Organizing Committee printed its statement in a single copy, and now they need to make $n$ more copies before the start of the Olympiad. They have access to two photocopiers, one of which copies a page in $x$ seconds, and the other in $y$ seconds. It is allowed to use either one photocopier or both simultaneously. Copies can be made not only from the original, but also from a copy.

Help the jury determine the minimum time required for this.

**Input**

The program takes three natural numbers as input: $n, x$, and $y$, separated by a space, where $1\le n\le 2\cdot 10^8$ and $1\le x,y\le 10$.

**Output**

A single number – the minimum time in seconds required to print $n$ copies.

**Examples**
---
**Input 1:**
```
4 1 1
```

**Output 1:**
```
3
```
---
**Input 2:**
```
4 1 1
```

**Output 2:**
```
4
```
---