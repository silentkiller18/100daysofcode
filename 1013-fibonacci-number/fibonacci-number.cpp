class Solution {
public:
    int fib(int n) {
        //bottom up DP
        //creating the dp array
        vector<int>dp(n+2);
        //VVI::here i have used vector of n+2 because in case of n=0 dp[1] will give error otherwise in generic way i Should write an if condition after dp[0] that if n==0 then return dp[0];
        //putting the base cases
        dp[0]=0;
        dp[1]=1;
        //fill rest of the dp array with the help of recursive relation i.e dp[n]=dp[n-1]+dp[n-2]
        for(int i=2;i<=n;i++){
            dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
        
     }
};