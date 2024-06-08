class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        set<int>s;
        for(auto i:nums) s.insert(i);
        int a = 0;
        for(auto i : s) nums[a] = i,a++;
        return s.size();
    }
};