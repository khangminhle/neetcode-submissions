class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, int> duplicates;
        for(int i = 0; i < nums.size(); i++) {
            if(duplicates.count(nums[i]) > 0) {
                return true;
            }

            duplicates[nums[i]] = 1;
        }
        return false;
    }
};