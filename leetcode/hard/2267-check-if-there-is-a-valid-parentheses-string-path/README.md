# Check if There Is a Valid Parentheses String Path

![Difficulty](https://img.shields.io/badge/Difficulty-Hard-red)

## Problem

A parentheses string is a  **non-empty**  string consisting only of `'('` and `')'`. It is  **valid**  if  **any**  of the following conditions is  **true** :

- It is ().
- It can be written as AB (A concatenated with B), where A and B are valid parentheses strings.
- It can be written as (A), where A is a valid parentheses string.

You are given an `m x n` matrix of parentheses `grid`. A  **valid parentheses string path**  in the grid is a path satisfying  **all**  of the following conditions:

- The path starts from the upper left cell (0, 0).
- The path ends at the bottom-right cell (m - 1, n - 1).
- The path only ever moves down or right.
- The resulting parentheses string formed by the path is valid.

Return `true`  *if there exists a  **valid parentheses string path**  in the grid.*  Otherwise, return `false`.

 

 **Example 1:** 

```
Input: grid = [["(","(","("],[")","(",")"],["(","(",")"],["(","(",")"]]
Output: true
Explanation: The above diagram shows two possible paths that form valid parentheses strings.
The first path shown results in the valid parentheses string "()(())".
The second path shown results in the valid parentheses string "((()))".
Note that there may be other valid parentheses string paths.

```

 **Example 2:** 

```
Input: grid = [[")",")"],["(","("]]
Output: false
Explanation: The two possible paths form the parentheses strings "))(" and ")((". Since neither of them are valid parentheses strings, we return false.

```

 

 **Constraints:** 

- m == grid.length
- n == grid[i].length
- 1 <= m, n <= 100
- grid[i][j] is either '(' or ')'.

## Solution

**Language:** Java  
**Runtime:** 3 ms (beats 100.00%)  
**Memory:** 47.4 MB (beats 94.29%)  
**Submitted:** 2026-09-29T18:23:49.140Z  

```java
class Solution {
    private boolean[][][] visited;

    public boolean hasValidPath(char[][] grid) {
        int m = grid.length, n = grid[0].length;
        if ((m + n - 1) % 2 != 0 || grid[0][0] == ')' || grid[m - 1][n - 1] == '(') {
            return false;
        }

        int maxBal = (m + n) / 2;
        visited = new boolean[m][n][maxBal + 1];

        return dfs(grid, 0, 0, 0, m, n, maxBal);
    }

    private boolean dfs(char[][] grid, int r, int c, int bal, int m, int n, int maxBal) {
        bal += (grid[r][c] == '(' ? 1 : -1);
        if (bal < 0 || bal > maxBal) return false;

        if (r == m - 1 && c == n - 1) {
            return bal == 0;
        }

        if (visited[r][c][bal]) return false;
        visited[r][c][bal] = true;

        if (r + 1 < m && dfs(grid, r + 1, c, bal, m, n, maxBal)) return true;
        if (c + 1 < n && dfs(grid, r, c + 1, bal, m, n, maxBal)) return true;

        return false;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/check-if-there-is-a-valid-parentheses-string-path/)