class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
          set<int>s;
        for(int i =0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
                return 1;
            s.insert(nums[i]);
        }
        return 0;
    }
    
};