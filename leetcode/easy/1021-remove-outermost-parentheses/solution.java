class Solution {
    public String removeOuterParentheses(String s) {
        Stack<Character> stack = new Stack<>();

        String ans = "";

        for(char ch : s.toCharArray()){
            if(ch == '('){
                if(!stack.isEmpty()) ans += "(";

                stack.push(ch);
            } 

            else{
                stack.pop();
                if(!stack.isEmpty()) ans += ")";
            }
        }

        return ans;
    }
}