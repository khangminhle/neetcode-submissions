class Solution {
public:
    bool checkValid(vector<int>& piles, int limit, int k) {
        int n = piles.size();
        double h = (double)limit;

        for(int i = 0; i < n; i++) {
            double time = (double)piles[i]/k;
            h -= ceil(time);


            if(h < 0) return false;
        }

        return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int max_piles = -1;
        int k = 1000000001;

        for(int i = 0; i < n; i++) {
            max_piles = max(max_piles, piles[i]);
        }

        int l = 1;
        int r = max_piles;

        while(l <= r) {
            int m = (l+r)/2;

            if(checkValid(piles, h, m)) {
                k = min(k, m);
                r = m-1;
            } else {
                l = m+1;
            }
        }

        return k;
    }
};