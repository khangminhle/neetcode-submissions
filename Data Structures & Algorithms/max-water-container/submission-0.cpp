class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int l = 0;
        int r = n-1;
        int max_amount = 0;
        while(l < r) {
            int area = min(heights[l], heights[r]) * (r-l);

            if(max_amount < area) {
                max_amount = area;
            }

            if(heights[l] < heights[r]) {
                l += 1;
            } else {
                r -= 1;
            }
        }

        return max_amount;
    }
};
