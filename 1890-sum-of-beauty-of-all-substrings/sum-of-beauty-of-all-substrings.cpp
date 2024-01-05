class Solution {
public:
    int beautySum(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); ++i) {
            int cnt[26] = {};
            for (int j = i; j < s.size(); ++j) {
                ++cnt[s[j] - 'a'];
                int mx = INT_MIN, mn = INT_MAX;
                for (int k = 0; k < 26; ++k) {
                    mx = max(mx, cnt[k]);
                    if (cnt[k]) mn = min(mn, cnt[k]);
                }
                ans += mx - mn;
            }
        }
        return ans;
    }
};