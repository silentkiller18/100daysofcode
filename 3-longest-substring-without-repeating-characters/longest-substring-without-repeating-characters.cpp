    class Solution {
    public:
        int lengthOfLongestSubstring(string s) {
        vector<int>mpp(256,-1);//we string can have 256 char
        int left =0,right=0;
        int n=s.size();
        int len=0;
        while(right<n){
            if(mpp[s[right]]!=-1) //if char right index exists or not we wont accept it if it is not greater than left

            left=max(mpp[s[right]]+1,left);//we wont accept if it is left of left thats why we used max
            mpp[s[right]]=right;
            len=max(len,right-left+1);//windowsize;
            right++;
        }
        return len;
        }
    };