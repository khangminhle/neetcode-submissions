
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> result;
        unordered_map<int, int> hm;
        priority_queue<pair<int,int>> maxheap;
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            hm[nums[i]] += 1;
        }

        for(auto& it: hm) {
            maxheap.push({it.second, it.first});
        }

        int count = 0;
        while(!maxheap.empty()) {
            pair<int, int> top = maxheap.top();
            result.push_back(top.second);
            count += 1;
            if(count == k) {
                return result;
            }
            maxheap.pop();
        }

        return {};
    }
};
