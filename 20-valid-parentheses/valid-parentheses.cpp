class Solution {
public:
    bool isValid(string s) {
        stack<char> t;
        for (int i=0; i<s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
                t.push(s[i]);
                continue;
            } 
            if (t.empty()) {
                return false;
            }
            if (s[i] == ')' && t.top() != '(') {
                return false;
            }
            if (s[i] == ']' && t.top() != '[') {
                return false;
            }
            if (s[i] == '}' && t.top() != '{') {
                return false;
            }
            t.pop();
        }
        return t.empty();
    }
};