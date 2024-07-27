class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
       map<int,int>freq;
       for(int i=0;i<=arr.size()-1;i++){
        freq[arr[i]]++;

       } 
       unordered_set<int>s;
       for(auto x:freq){
        s.insert(x.second);

       }
       return freq.size()==s.size();
    }
};