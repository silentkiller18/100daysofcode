#include<bits/stdc++.h>
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int>res(n);
        int productOfAllBeforeCurrent=1;
        int productOfAllAfterCurrent=1;


for(int i=0;i<n;i++){
    res[i]=productOfAllBeforeCurrent;
    productOfAllBeforeCurrent*=nums[i];
}
for(int i=n-1;i>=0;i--){
    res[i]*=productOfAllAfterCurrent;
    productOfAllAfterCurrent*=nums[i];
}
return res;

    }
};