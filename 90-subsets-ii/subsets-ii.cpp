class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> subset;
        set<vector<int>> result;
        subsetsUtil(nums, result, subset, 0);
        vector<vector<int>> answer;
        for(auto it:result){
            answer.push_back(it);
        }
        return answer;
    }
public:
    void subsetsUtil(vector<int>& nums, set<vector<int>>& result, vector<int>& subset, int index) {
        result.insert(subset);
        for(int i = index; i < nums.size(); i++){
            subset.push_back(nums[i]);
            subsetsUtil(nums, result, subset, i + 1);
            subset.pop_back();
        }
        return;
    }
};