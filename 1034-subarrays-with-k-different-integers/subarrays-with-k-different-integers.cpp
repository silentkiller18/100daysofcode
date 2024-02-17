class Solution {
public:
int func(vector<int>&nums,int k){
    unordered_map<int,int>mp;
    int i =0,j=0,ans=0;
    while(j<nums.size()){
        mp[nums[j]]++;

        while(mp.size()>k){
            mp[nums[i]]--;
            if(mp[nums[i]]==0)

            mp.erase(nums[i]);
            i++;
        }
ans+=(j-i+1);
j++;
    }
return ans;
}
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int c1=func(nums,k);
        int c2=func(nums,k-1);
        return (c1-c2);
    }
};