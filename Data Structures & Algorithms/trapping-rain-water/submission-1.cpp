class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();

        int max_left = height[0];
        int max_right = height[n-1];
        int left = 0;
        int right = n-1;
        int total_amount = 0;
        for(int i = 1; i < n; i++) {
            if(height[i] != 0 && height[i] >= max_left) {
                int amount = min(height[i], max_left) * (i-left-1);
                for(int j = left+1; j < i; j++) {
                    amount -= height[j];
                }
                total_amount += amount;
                max_left = height[i];
                left = i;
            }
        }

        for(int i = right-1; i >= left; i--) {
            if(height[i] != 0 && height[i] >= max_right) {
                int amount = min(height[i], max_right) * (right-i-1);
                for(int j = i+1; j < right; j++) {
                    amount -= height[j];
                }
                total_amount += amount;
                max_right = height[i];
                right = i;
            }
        }
        return total_amount;
    }
};
