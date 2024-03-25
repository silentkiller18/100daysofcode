class Solution {
public:
    int ladderLength(string str1, string str2, vector<string>& str) {
        queue<pair<string,int>> q;
        q.push({str1,1});
        unordered_set<string> st(str.begin(),str.end());
        if(st.find(str2)==st.end()) return 0;
        while(!q.empty()){
            string word=q.front().first;
            int steps=q.front().second;
            q.pop();
            if(word==str2) return steps;
            for(int i=0;i<word.size();i++){
                char orig=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.find(word)!=st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i]=orig;
            }
        }
        return 0;
    }
};