class Solution {
public:
    int climbStairs(int n) {
          int curr,prev1=0,prev2=1;
    for(int i=0;i<=n;i++)
    {
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
    }
    return prev1;
    }
};