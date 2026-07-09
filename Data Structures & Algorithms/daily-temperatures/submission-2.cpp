class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();

        vector<int> st;
        vector<int>res(n, 0);

        for(int i = 0; i < n; i++) {
            if(st.empty()) {
                st.push_back(i);
                continue;
            }

            int curr = st.back();
            while(temperatures[curr] < temperatures[i]) {
                st.pop_back();
                res[curr] = i-curr;
                if(st.empty()) break;
                curr = st.back();
            }

            st.push_back(i);
        }
        return res;
    }
};
