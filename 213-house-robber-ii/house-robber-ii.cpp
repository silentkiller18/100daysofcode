class Solution {
public:
    int maxi(vector<int>& nums) {
        int n=nums.size();
        int p2=0;
        int p=nums[0];
        int curr,pick,notpick;
        for (int i=1;i<n;i++){
            pick=nums[i];
            if(i>1)
                pick=pick+p2;
            notpick=0+p;
            curr=max(pick,notpick);
            p2=p;
            p=curr;
        }
        return p;
    }

    int rob(vector<int>& nums) {
        vector<int> nums1=nums;
        vector<int> nums2=nums;
        nums1.erase(nums1.begin());
        nums2.pop_back();
        return max(maxi(nums1),maxi(nums2));
        
    }
};