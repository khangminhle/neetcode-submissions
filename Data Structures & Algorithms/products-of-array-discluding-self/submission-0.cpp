class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> result;

        vector<int> prefix;

        prefix.push_back(1);

        int n = nums.size();

        for(int i = 1; i < n; i++) {
            prefix.push_back(nums[i-1]*prefix[i-1]);
            cout<<nums[i-1]<<" "<<prefix[i-1]<<endl;
        }
        int product = 1;
        for(int i = n-2; i >= 0; i--) {
            product = product * nums[i+1];
            prefix[i] = prefix[i] * product;
        }

        return prefix;
    }
};