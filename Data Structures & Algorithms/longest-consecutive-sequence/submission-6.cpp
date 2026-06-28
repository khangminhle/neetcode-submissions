class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        
        unordered_set<int> hm;

        for(int i = 0; i < n; i++) {
            hm.insert(nums[i]);
        }
        int max_count = 0;
        for(const auto& val: hm) {
            if(hm.count(val-1) != 0) continue;

            int count = 1;
            int next_number = val+1;
            while(hm.count(next_number)) {
                count += 1;
                next_number += 1;
            }

            if(count > max_count) {
                max_count = count;
            }
        }

        return max_count;
        
    }
};
