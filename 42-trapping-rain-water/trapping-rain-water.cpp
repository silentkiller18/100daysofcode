class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> L(n,0);
        vector<int> R(n,0);
        int ans=0;
        int maximum=INT_MIN;
        int minimum=INT_MAX;
        for(int i=0;i<n;++i){
            maximum = max(maximum,height[i]);
            L[i] = maximum;
        }
        maximum=0;
        for(int i=n-1;i>=0;--i){
            maximum = max(maximum,height[i]);
            R[i] = maximum;
        }
        for(int i=0;i<n;++i)
            ans += min(L[i],R[i]) - height[i];
        return ans;
    }
};