class Solution {
public:
    int search(vector<int>& nums, int target) {
        int hi = nums.size();
        int lo = -1;
        int mid;
        while (hi > lo + 1) {
            mid = (hi + lo) / 2;
            if (target == nums[mid]) return mid;
            if (target > nums[mid]) {
                lo = mid;
            } else {
                hi = mid;
            }
        }
        return -1;
    }
};