class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;

        for(int i = 0; i < n-2; i++) {
            int l = i+1;
            int r = n-1;
            int first_num = nums[i];

            if(i > 0) {
                if(first_num == nums[i-1]) continue;
            }

            int second_num = nums[l];
            int third_num = nums[r];

            if(first_num > 0) break;

            while(l < r) {

                int second_num = nums[l];
                int third_num = nums[r];
                int sum = first_num + second_num + third_num;
                if(sum < 0) {
                    l += 1;
                    continue;
                }

                if(sum > 0){
                    r -= 1;
                    continue;
                }

                if(sum == 0) {
                    result.push_back({first_num, second_num, third_num});
                    while(l < r && nums[l] == nums[l+1]) l += 1;
                    while(l < r && nums[r] == nums[r-1]) r -= 1;
                    l += 1;
                    r -= 1;
                }


            }
        }


        return result;
    }
};
