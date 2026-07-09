class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<pair<int,int>> st;
        vector<int>res(n, 0);

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push_back({temperatures[i], i});
                continue;
            }

            pair<int,int> curr = st.back();
            while(curr.first < temperatures[i]) {
                st.pop_back();
                res[curr.second] = i-curr.second;
                if(st.empty()) break;
                curr = st.back();
            }

            st.push_back({temperatures[i], i});
        }
        return res;
    }
};
