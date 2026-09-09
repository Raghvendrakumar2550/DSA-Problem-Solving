# stickler-theif-1587115621

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

_Description not available._

## Solution

**Language:** Java  
**Runtime:** N/A  
**Memory:** N/A  
**Submitted:** 2026-09-09T08:23:14.871Z  

```java
class Solution {
    public int findMaxSum(int arr[]) {
        int n = arr.length;
        if (n == 0) return 0;
        if (n == 1) return arr[0];

        int prev2 = arr[0];
        int prev1 = Math.max(arr[0], arr[1]);

        for (int i = 2; i < n; i++) {
            int curr = Math.max(prev1, prev2 + arr[i]);
            prev2 = prev1;
            prev1 = curr;
        }

        return prev1;
    }
}

```

---

[View on GeeksforGeeks](https://practice.geeksforgeeks.org/problems/stickler-theif-1587115621/1)