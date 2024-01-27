class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int sum=0;
        int count=0;
        for(auto it:nums){
            sum +=it;
            if(sum == k){
                   count++;
               }
            int find = sum-k;
            if(mp.find(find)!=mp.end()){
                count +=mp[find];
            }
            mp[sum]++;
        }
        return count;
    }
};