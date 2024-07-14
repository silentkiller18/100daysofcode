class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string a;
        for(int i=0;i<s.size();i++){
            if(s[i]!= ' '){
                a.push_back(s[i]);
            } else if(!a.empty()){
                st.push(a);
                a.clear();
            }
        }
        if(!a.empty()) st.push(a);
        string ans;
        while(!st.empty()){
            // if(st.top()=="") continue;
            // else {
                ans += st.top() + " ";
                st.pop();
            // }
        }
        ans.pop_back(); // remove the extra space at the end
        return ans;
    }
};