class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int slow = 0;
        int fast = 0;
        int m = 0;
        while (slow<nums.size()) {
            if (nums[slow] == val) {
                m++;
            }
            while (fast < nums.size() && nums[fast] == val) {
                fast++;
            }
            if (fast < nums.size()) {
                nums[slow] = nums[fast];
            } else {
                nums[slow] = -1;
            }
            slow++;
            fast++;
        }
        return nums.size() - m;
    }
};