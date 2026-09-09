class Solution {
    public static boolean subset(int arr[],int sum,int idx,Boolean dp[][]){
        if(sum==0) return true;
        if(idx==0){
            return (arr[0]==sum);
        }
        if(dp[idx][sum]!=null) return dp[idx][sum];
        boolean notpick=subset(arr,sum,idx-1,dp);
        boolean pick=false;
        if(sum>=arr[idx]){
            pick=subset(arr,sum-arr[idx],idx-1,dp);
        }
        return dp[idx][sum]=pick || notpick;
    }
    // static Boolean isSubsetSum(int arr[], int sum) {
    //     int n=arr.length;
    //     boolean dp[][]=new boolean[n][sum+1];
    //     // return subset(arr,sum,n-1,dp);
        
    //     for(int i=0;i<n;i++){
    //         dp[i][0]=true;
    //     }
    //     if(arr[0]<=sum){
    //         dp[0][arr[0]]=true;
    //     }
    //     for(int i=1;i<n;i++){
    //         for(int j=1;j<sum+1;j++){
    //             boolean notpick=dp[i-1][j];
    //             boolean pick=false;
    //             if(j>=arr[i]){
    //                 pick=dp[i-1][j-arr[i]];
    //             }
    //             dp[i][j]=pick || notpick;
    //         }
    //     }
    //     return dp[n-1][sum];
        
        
            
    // }
    // spaceoptimization
    static Boolean isSubsetSum(int arr[], int sum) {
        int n=arr.length;
        boolean dp[][]=new boolean[2][sum+1];
        // return subset(arr,sum,n-1,dp);
        dp[0][0]=true;
        dp[1][0]=true;
        if(arr[0]<=sum){
            dp[0][arr[0]]=true;
        }
        for(int i=1;i<n;i++){
            int curr=i%2;
            int prev=(i-1)%2;
            for(int j=1;j<sum+1;j++){
                boolean notpick=dp[prev][j];
                boolean pick=false;
                if(j>=arr[i]){
                    pick=dp[prev][j-arr[i]];
                }
                dp[curr][j]=pick || notpick;
            }
            curr=prev;
        }
        return dp[(n - 1) % 2][sum]; 
        
        
            
    }
}