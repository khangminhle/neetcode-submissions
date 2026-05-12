class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> setNum;

        for(int i = 0; i < nums.size(); i++) {
            int findNumber = target - nums[i];

            if(setNum.count(findNumber) > 0) {
                return {setNum[findNumber], i};
            }

            setNum[nums[i]] = i;
        }

        return {};
    }
};
