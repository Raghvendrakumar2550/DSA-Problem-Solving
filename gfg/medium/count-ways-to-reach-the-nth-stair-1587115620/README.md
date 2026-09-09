# count-ways-to-reach-the-nth-stair-1587115620

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-09T08:26:08.227Z  

```java
class Solution {
    public int countWays(int n) {
        if (n <= 2) return n;
        int a = 1, b = 2;
        for (int i = 3; i <= n; i++) {
            int c = a + b;
            a = b;
            b = c;
        }
        return b;
    }
}

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/count-ways-to-reach-the-nth-stair-1587115620/1)