class Solution {
public:
    int jump(vector<int>& nums) {
      int maxJump=0,currentMax=0,Jump=0;

      for(int i=0;i<nums.size()-1;i++){
          maxJump=max(maxJump,i+nums[i]);

          if(i==currentMax){
              Jump++;
              currentMax=maxJump;

          }
      }  
      return Jump;
    }
};