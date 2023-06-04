class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = -1;
        while (hi - lo > 1) {
            int mid = (hi + lo)/2;
            if (nums[mid] == target) {
                return mid;
            } else if (target > nums[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return hi;
    }
};