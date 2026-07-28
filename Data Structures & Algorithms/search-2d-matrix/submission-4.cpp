class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0;
        int r = n-1;

        while(l <= r) {
            int m = (l+r)/2;

            if(matrix[m][0] == target) return true;
            if(matrix[m][0] > target) r -= 1;
            if(matrix[m][0] < target) l += 1;
        }
        
        int row = -1;

        if(l >= 0 && l <= n-1 && matrix[l][0] <= target && matrix[l][m-1] >= target) {
            row = l;
        }

        if(r <= n-1 && r >= 0 && matrix[r][0] <= target && matrix[r][m-1] >= target) {
            row = r;
        }

       

        if(row == -1) return false;

        int ll = 0;
        int rr = m-1;
        
        while(ll <= rr) {
            int mm = (ll+rr)/2;

            if(matrix[row][mm] == target) return true;
            if(matrix[row][mm] > target) rr -= 1;
            if(matrix[row][mm] < target) ll += 1;
        }

        return false;
    }
};
