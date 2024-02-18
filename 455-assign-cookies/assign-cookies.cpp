class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int right =0,left=0;
        if(g.size()==0 || s.size()==0)
        return 0;

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());

while(right<g.size() && left<s.size()){
    if(s[left]>=g[right])
    right++;
    left++;
}
return right;
    }
};