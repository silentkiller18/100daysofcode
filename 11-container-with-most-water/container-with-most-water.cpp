class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(); 

        int start = 0; 
        int end = n - 1;

        int area = 0; 
        int result = 0; 
        
        while (start < end) {
            int breadth = end - start; // Calculate the distance (breadth) between the two pointers
            area = breadth * min(height[start], height[end]); // Calculate the area between the two lines
            result = max(area, result);

            // Move the pointer pointing to the shorter line towards the center
            if (height[start] <= height[end]) {
                start++;
            } else {
                end--;
            }
        } 

        return result; 
    }
};