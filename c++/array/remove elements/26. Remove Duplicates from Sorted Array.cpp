class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int val = nums[0];
        int slow = 0;
        int fast = 0;
        for (;fast < nums.size(); fast++) {
            if (nums[fast] != val) {
                slow++;
                val = nums[fast];
                nums[slow] = nums[fast];
            }
        }
        return slow+1;
    }
};