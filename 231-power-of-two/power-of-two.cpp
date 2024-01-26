class Solution {
public:
    bool isPowerOfTwo(long long int n) {
        return(n!=0)&&((n&(n-1))==0);

    }
};