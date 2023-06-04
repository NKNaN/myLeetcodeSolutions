class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> output(nums);
        int hi_nums = nums.size() - 1;
        int hi_output = nums.size() - 1;
        int lo_nums = 0;
        while (hi_nums >= lo_nums) {
            if (nums[hi_nums]*nums[hi_nums] > nums[lo_nums]*nums[lo_nums]) {
                output[hi_output] = nums[hi_nums]*nums[hi_nums];
                hi_nums--;
                hi_output--;
            } else {
                output[hi_output] = nums[lo_nums]*nums[lo_nums];
                lo_nums++;
                hi_output--;
            }
        }
        return output;
    }
};