class Solution {
public:
    int strStr(string big, string small) {
        if(big.size()<small.size())return -1;
        for(int i=0;i<=big.size()-small.size();i++)
            if(big.substr(i,small.size())==small) return i;
    return -1;
    }
};