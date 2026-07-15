class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(-1);

        int n = heights.size();
        vector<int> hStack;
        int max_area = 0;
        for(int i = 0; i < n; i++) {
            while(!hStack.empty() && heights[hStack.back()] >= heights[i]) {

                int index = hStack.back();
                int previous_index;
                hStack.pop_back();
                if(hStack.empty()) {
                    previous_index = -1;
                } else {
                    previous_index = hStack.back();
                }

                int area = heights[index] * (i-previous_index-1);
                if(area > max_area) {
                    max_area = area;
                }
            }

            hStack.push_back(i);
        }

        return max_area;
    }
};
