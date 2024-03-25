class Solution {
public:
    int ladderLength(string s, string t, vector<string>& w) {
          set<string>st;
        for(int i=0;i<w.size();i++){
            st.insert(w[i]);
        }
        queue<pair<string,int>>q;
        q.push({s,0});
        st.erase(s);
        while(!q.empty()){
            auto curr=q.front();
            string str=curr.first;
            int d=curr.second;
            q.pop();
            if(str==t) return d+1;
            for(int i=0;i<str.length();i++){
                string t=str;
                for(char it='a';it<='z';it++){
                    t[i]=it;
                    if(st.count(t)){
                        st.erase(t);
                        q.push({t,d+1});
                        
                    }
                }
            }
        }
        return 0;   
    }
};