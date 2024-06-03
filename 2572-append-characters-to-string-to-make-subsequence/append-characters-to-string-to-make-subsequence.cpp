// Greedy O(n1 + n2)
class Solution {
public:
    int appendCharacters(string s, string t) {
        int is = 0, it = 0;
        while(is < s.size() && it < t.size()) {
            if(s[is] == t[it]) {
                it++;
            }
            is++;
        }
        return t.size() - it;
    }
};