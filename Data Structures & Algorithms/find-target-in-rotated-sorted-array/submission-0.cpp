class Solution {
public:
	int search(vector<int> &nums, int target) {
		int n = nums.size();
        int l = 0;
        int r = n-1;
        int mid;

        while(l <= r) {
           mid = l + (r-l)/2;

           if(nums[mid] >= nums[r]) {
               l = mid+1;
           } else {
               r = mid;
           }
        }

        if(mid == 0) {
            l = 0;
            r = n-1;
        } else {
            if(target > nums[n-1]) {
                l = 0;
                r = mid-1;
            } else {
                l = mid;
                r = n-1;
            }
        }

        while(l <= r) {
           mid = l + (r-l)/2;

           if(nums[mid] == target) return mid;
           if(nums[mid] > target) r = mid-1;
           if(nums[mid] < target) l = mid+1;
        }
        return -1;
	}

};
