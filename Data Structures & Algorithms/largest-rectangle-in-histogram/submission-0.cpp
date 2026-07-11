class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        int max_area = 0;
        int min_height = 1001;

        for(int i = 0; i < n; i++) {
            if(heights[i] < min_height) {
                min_height = heights[i];
            }

            max_area = max(max_area, heights[i]);

            if(i == 0) continue;
            
            int current_min = heights[i];
            for(int j = i-1; j >= 0; j--) {
                if(heights[j] == 0) break;

                if(heights[j] < current_min) {
                    current_min = heights[j];
                }

                int area = current_min * (i-j+1);

                max_area = max(area, max_area);
            }
        }
        return max_area;
    }
};
