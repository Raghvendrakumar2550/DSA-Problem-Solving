# Vowel-Consonant Score

![Difficulty](https://img.shields.io/badge/Difficulty-Easy-green)

## Problem

You are given a string `s` consisting of lowercase English letters, spaces, and digits.

Let `v` be the number of vowels in `s` and `c` be the number of consonants in `s`.

A vowel is one of the letters `'a'`, `'e'`, `'i'`, `'o'`, or `'u'`, while any other letter in the English alphabet is considered a consonant.

The  **score**  of the string `s` is defined as follows:

- If c > 0, the score = floor(v / c) where floor denotes rounding down to the nearest integer.
- Otherwise, the score = 0.

Return an integer denoting the score of the string.

 

 **Example 1:** 

 **Input:**  s = "cooear"

 **Output:**  2

 **Explanation:** 

The string `s = "cooear"` contains `v = 4` vowels `('o', 'o', 'e', 'a')` and `c = 2` consonants `('c', 'r')`.

The score is `floor(v / c) = floor(4 / 2) = 2`.

 **Example 2:** 

 **Input:**  s = "axeyizou"

 **Output:**  1

 **Explanation:** 

The string `s = "axeyizou"` contains `v = 5` vowels `('a', 'e', 'i', 'o', 'u')` and `c = 3` consonants `('x', 'y', 'z')`.

The score is `floor(v / c) = floor(5 / 3) = 1`.

 **Example 3:** 

 **Input:**  s = "au 123"

 **Output:**  0

 **Explanation:** 

The string `s = "au 123"` contains no consonants `(c = 0)`, so the score is 0.

 

 **Constraints:** 

- 1 <= s.length <= 100
- s consists of lowercase English letters, spaces and digits.

## Solution

**Language:** Java  
**Runtime:** 1 ms (beats 100.00%)  
**Memory:** 43.5 MB (beats 70.23%)  
**Submitted:** 2026-09-16T17:29:05.644Z  

```java
class Solution {
    public int vowelConsonantScore(String s) {
        int vowels = 0;
        int consonants = 0;

        for(int i =0; i <s.length();i++){
            char ch = s.charAt(i);

            if(Character.isLetter(ch)){
                if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
                    vowels++;
                }else{
                    consonants++;
                }
            }
        }
        if(consonants == 0){
            return 0;
        }
        return vowels/ consonants;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/vowel-consonant-score/)