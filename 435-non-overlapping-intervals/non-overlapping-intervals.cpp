class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int i=0,j=1;
        if(intervals.size()<=1)return 0;
        sort(intervals.begin(),intervals.end());
        int count=0;
        while(j<intervals.size()){
            if(intervals[i][1]<=intervals[j][0]){
                i=j;
                j++;
            }
            else if(intervals[i][1]<=intervals[j][1]){
                count++;
                j++;
            }
            else if(intervals[i][1]>intervals[j][1]){
                count++;
                i=j;
                j++;
            }
        }
        return count;
    }
};