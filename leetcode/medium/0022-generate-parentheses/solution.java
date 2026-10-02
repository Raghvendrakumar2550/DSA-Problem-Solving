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