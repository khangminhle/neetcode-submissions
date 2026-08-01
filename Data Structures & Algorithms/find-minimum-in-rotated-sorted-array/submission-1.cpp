class Solution {
public:
	int findMin(vector<int> &nums) {
		int n = nums.size();
		int low = 1;
		int high = n;
		int res = -1;
		while(low <= high) {
			int mid = (low+high)/2;
			cout<<n-mid<<endl;	
			if(nums[n-mid] > nums[0]) {
				high = mid-1;
			} else {
                if(mid == n) break;
				res = mid;
				low = mid+1;
			}
		}
		if(res == -1) res = n;
		return nums[n-res];
	}

};
