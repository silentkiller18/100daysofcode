class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> res;

        if (nums.empty()) {
            return {};
        }
        long int start = nums[0];
        long int end = nums[0];
        for (const auto& el : nums) {
            if (el - end > 1) {
                if (start != end) {
                    res.push_back(to_string(start) + "->" + to_string(end));
                } else {
                    res.push_back(to_string(start));
                }
                start = end = el;
            }
            end = el;
        }

        if (start != end) {
            res.push_back(to_string(start) + "->" + to_string(end));
        } else {
            res.push_back(to_string(start));
        }

        return res;
    }
};