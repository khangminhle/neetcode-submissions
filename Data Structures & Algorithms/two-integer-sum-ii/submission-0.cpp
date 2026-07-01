class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int n = numbers.size();
       unordered_map<int, int> hm;
       for(int i = 0; i < n; i++) {
           int left = target - numbers[i];
           if(hm.count(left) > 0) {
               return {hm[left]+1, i+1};
           }
           hm[numbers[i]] = i;
       }
       return {};
    }
};
