class Solution {
    public long countCommas(long n) {
        long ans=0;
        long start=1;
        while(start<=n){
            long end=start*10-1;
            long digits=String.valueOf(start).length();
            long commas=(digits-1)/3;
            long right=Math.min(end,n);
            ans+=(right-start+1)*commas;
            start*=10;
            
        }
        return ans;
    }
}