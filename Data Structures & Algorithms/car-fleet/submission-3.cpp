class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>> cars(n);
        vector<float> times;

        for(int i = 0; i < n; i++) {
            cars[i] = {position[i], speed[i]};
        }

        sort(cars.begin(), cars.end());

        
        for(int i = n-1; i >= 0; i--) {
            float time = (float)(target-cars[i].first) / cars[i].second;

            if(times.empty()) {
                times.push_back(time);
                continue;
            }

            float previous_time = times.back();

            if(time > previous_time) {
                times.push_back(time);
            }
        }



        return times.size();
    }
};
