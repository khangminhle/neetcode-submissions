class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0;
        int l = 0;
        int r = n-1;
        int max_left = height[l];
        int max_right = height[r];

        while(l < r) {
            if(max_left <= max_right) {
                int amount = min(max_left, max_right) - height[l];
                if(amount > 0) {
                    total += amount;
                }

                l += 1;

                if(max_left < height[l]) {
                    max_left = height[l];
                }

            } else {
                int amount = min(max_left, max_right) - height[r];

                if(amount > 0) {
                    total += amount;
                }

                r -= 1;

                if(max_right < height[r]) {
                    max_right = height[r];
                }

            }
        }


        return total;
    }
};
