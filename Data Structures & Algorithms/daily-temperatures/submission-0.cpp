class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> res;

        for(int i = 0; i < n-1; i++) {
            int temp = 0;
            for(int j = i+1; j < n; j++) {
                if(temperatures[j] > temperatures[i]) {
                    temp = j-i;
                    break;
                }
            }
            res.push_back(temp);
        }
        res.push_back(0);

        return res;
    }
};
