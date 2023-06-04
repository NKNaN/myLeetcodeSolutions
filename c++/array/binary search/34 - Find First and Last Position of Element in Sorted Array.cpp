class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> ret = {-1, -1};
        int hi = nums.size();
        int lo = -1;
        if (searchIndex(nums, target, lo, hi) == -1) {
            return ret;
        }
        int sub_lo = searchInsertIndex(nums, target - 0.5, lo, hi);
        int sub_hi = searchInsertIndex(nums, target + 0.5, lo, hi) - 1;
        ret[0] = sub_lo;
        ret[1] = sub_hi;
        return ret;
    }
    int searchIndex(vector<int>& nums, int target, int lo, int hi) {
        int mid = 0;
        while (hi - lo > 1) {
            mid = (hi + lo)/2;
            if (target > nums[mid]) {
                lo = mid;
            } else if (target < nums[mid]) {
                hi = mid;
            } else {
                return mid;
            }
        }
        return -1;
    }
    // double target
    int searchInsertIndex(vector<int>& nums, double target, int lo, int hi) {
        int mid = 0;
        while (hi - lo > 1) {
            mid = (hi + lo)/2;
            if (target > nums[mid]) {
                lo = mid;
            } else if (target < nums[mid]) {
                hi = mid;
            } else {
                return mid;
            }
        }
        return hi;
    }
};