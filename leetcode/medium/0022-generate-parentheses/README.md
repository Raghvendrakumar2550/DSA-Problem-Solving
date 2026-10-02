# Generate Parentheses

![Difficulty](https://img.shields.io/badge/Difficulty-Medium-yellow)

## Problem

Given `n` pairs of parentheses, write a function to  *generate all combinations of well-formed parentheses*.

 

 **Example 1:** 

```
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

```

 **Example 2:** 

```
Input: n = 1
Output: ["()"]

```

 

 **Constraints:** 

- 1 <= n <= 8

## Solution

**Language:** Java  
**Runtime:** 20 ms (beats 5.11%)  
**Memory:** 47.1 MB (beats 5.03%)  
**Submitted:** 2026-10-02T17:35:07.929Z  

```java
class Solution {
    public boolean isvalid(String ss) {
        int m=ss.length();
        Stack<Character> st = new Stack<>();
        for(int i=0;i<m;i++){
            char ch=ss.charAt(i);
            if(ch=='('){
                st.push(')');
            }
            else if(ch=='{'){
                st.push('}');
            }
            else if(ch=='['){
                st.push(']');
            }
            else if(st.isEmpty() || st.peek()!=ch){
                return false;
            }
            else{
                st.pop();
            }
        }
        return st.isEmpty();
    }
    void solve(int n,List<String> ans,String s){
        if(s.length()==2*n){
            if(isvalid(s)){
            ans.add(s);
            
            }
            return;
        }
        solve(n,ans,s+"(");  
        solve(n,ans,s+")");    
    }
    public List<String> generateParenthesis(int n) {
        String s="";
        List<String> ans=new ArrayList<>();
        solve(n,ans,s);
        return ans;
    }
}
```

---

[View on LeetCode](https://leetcode.com/problems/generate-parentheses/)