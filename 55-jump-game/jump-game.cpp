class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n =nums.size()-1;
      int LastPos=n;
      for(int i =n-1;i>=0;i--){
          if(i+nums[i]>=LastPos){
              LastPos=i;
          }

      }  
      return LastPos==0;
    }
};