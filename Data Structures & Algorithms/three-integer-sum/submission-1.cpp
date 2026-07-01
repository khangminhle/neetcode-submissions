class Solution {
public:
    bool checkDuplicate(vector<vector<int>> &nums, vector<int> triplets) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i][0] == triplets[0] && nums[i][1] == triplets[1]) return true;
        }
        return false;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> index_hm;
        unordered_set<int> included_hm;
        vector<vector<int>> result = {};

        for(int i = 0; i < n; i++) {
            index_hm[nums[i]].push_back(i);
        }

        for(int i = 0; i < n-2; i++) {
            for(int j = i+1; j < n-1; j++) {
                int left = 0 - (nums[j]+nums[i]);
                if(index_hm.count(left) == 0) continue;

                for(int k = 0; k < index_hm[left].size(); k++) {
                    if(index_hm[left][k] > j) {
                        vector<int> triplets = {nums[i], nums[j], left};
                        sort(triplets.begin(), triplets.end());
                        if(checkDuplicate(result, triplets) == false) {
                            result.push_back(triplets);
                        } else {
                            break;
                        }
                            
                    }
                }
            }
        }
        //for(int i = 0; i < result.size(); i++) {
            //cout<<result[i][0]<<" "<<result[i][1]<<" "<<result[i][2]<<endl;
        //}
        return result;
    }
};
