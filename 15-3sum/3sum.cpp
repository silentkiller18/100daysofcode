class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        vector<vector<int>>res;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0)break;
            if(i>0&&nums[i]==nums[i-1])continue;//same element hoga to check krne ke lie


            int j=i+1,r=nums.size()-1;
            while(j<r){
                int sum=nums[i]+nums[j]+nums[r];
                if(sum>0){
                    r--;
                }
                else if(sum<0){
                    j++;

                }
                else{
                    res.push_back({nums[i],nums[j],nums[r]});
                    j++;
                    r--;

                    while(j<r&&nums[j]==nums[j-1]){
                        j++;//same element hoga uslo check krne ke lie
                    }
                    
                }
            }
        }
        return res;
    }
};
