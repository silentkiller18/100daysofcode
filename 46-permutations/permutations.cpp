class Solution {
public:
    void permute(int indx, vector<int>& nums, vector<vector<int>>& ans){
        if(indx == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=indx; i<nums.size(); i++){
            swap(nums[indx], nums[i]);
            permute(indx+1, nums, ans);
            swap(nums[indx], nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        permute(0, nums, ans);
        return ans;
        
    }
};