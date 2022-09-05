class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int>mp;
        for(int i=0;i<arr.size();i++)
            mp[arr[i]]++;
        set<int>s;
        for(auto a:mp)
            s.insert(a.second);
        if(mp.size()==s.size())
            return true;
        return false;
    }
    
};