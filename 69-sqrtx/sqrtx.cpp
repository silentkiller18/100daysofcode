class Solution {
public:
    int mySqrt(int x) {
        int left = 1;
        int right = x;
        int mid = -1;

        while(left <= right){
            // avoid overflow
            mid = left + (right-left)/2;

            if(mid == x/mid) return mid;
            if(mid > x/mid) right = mid - 1;
            else left = mid + 1;
        }

        return right;
    }
};