# Maximize Sum of Squares of Digits

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

You are given two  **positive**  integers `num` and `sum`.

A positive integer `n` is  **good**  if it satisfies both of the following:

- The number of digits in n is exactly num.
- The sum of digits in n is exactly sum.

The  **score**  of a  **good**  integer `n` is the sum of the squares of digits in `n`.

Return a  **string**  denoting the  **good**  integer `n` that achieves the  **maximum**   **score**. If there are multiple possible integers, return the  **maximum** ​​​​​​​one. If no such integer exists, return an empty string.

 

 **Example 1:** 

 **Input:**  num = 2, sum = 3

 **Output:**  "30"

 **Explanation:** 

There are 3 good integers: 12, 21, and 30.

- The score of 12 is 12 + 22 = 5.
- The score of 21 is 22 + 12 = 5.
- The score of 30 is 32 + 02 = 9.

The maximum score is 9, which is achieved by the good integer 30. Therefore, the answer is `"30"`.

 **Example 2:** 

 **Input:**  num = 2, sum = 17

 **Output:**  "98"

 **Explanation:** 

There are 2 good integers: 89 and 98.

- The score of 89 is 82 + 92 = 145.
- The score of 98 is 92 + 82 = 145.

The maximum score is 145. The maximum good integer that achieves this score is 98. Therefore, the answer is `"98"`.

 **Example 3:** 

 **Input:**  num = 1, sum = 10

 **Output:**  ""

 **Explanation:** 

There are no integers that have exactly 1 digit and whose digits sum to 10. Therefore, the answer is `""`.

 

 **Constraints:** 

- 1 <= num <= 2 * 105
- 1 <= sum <= 2 * 106

## Solution

**Language:** Java  
**Runtime:** 51 ms (beats 74.39%)  
**Memory:** 47.3 MB (beats 98.78%)  
**Submitted:** 2026-10-14T18:26:06.805Z  

```java
class Solution {
    public String maxSumOfSquares(int num, int sum) {
        if (sum > 9L * num) return "";

        StringBuilder sb = new StringBuilder();
        int q = sum / 9;
        int r = sum % 9;

        for (int i = 0; i < q; i++) {
            sb.append('9');
        }
        if (r > 0) {
            sb.append((char) ('0' + r));
        }
        while (sb.length() < num) {
            sb.append('0');
        }
        return sb.toString();
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/maximize-sum-of-squares-of-digits/)