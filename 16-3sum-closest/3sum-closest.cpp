class Solution {
public:
    int threeSumClosest(vector<int>& nums, int t) {
        int n=nums.size();
        if(n==3){
            return nums[0]+nums[1]+nums[2];
        }
        sort(nums.begin(),nums.end());
        int ans=0,prev_d=INT_MAX;
        for(int i=0;i<n;i++){
            int low=i+1,high=n-1;
            while(low<high){
                int sum=nums[i]+nums[low]+nums[high];
                if(sum==t){
                    return sum;
                }
                else if(sum>t){
                    high--;
                }
                else{
                    low++;
                }
                
                if(prev_d>abs(sum-t)){
                    ans=sum;
                }
                prev_d=min(prev_d,abs(sum-t));
            }
        }
        return ans;
    }
};