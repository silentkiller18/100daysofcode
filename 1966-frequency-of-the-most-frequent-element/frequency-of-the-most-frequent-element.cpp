class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
     long long int ans=0;
         long int sum=0;
        long long int j=0;
        for(long long int i=0;i<nums.size();i++){
            sum+=nums[i];
            while((long long)((i-j+1)*nums[i]-sum)>k){
                sum-=nums[j];
                j++;
            }
            ans=max(ans,(i-j+1));
        }
        return ans;
        
    }
};