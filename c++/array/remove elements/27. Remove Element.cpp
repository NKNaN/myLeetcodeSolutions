class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector<int> stack;
        int k = 0;
        for (int i=0; i<nums.size(); i++) {
            int tmp = nums[i];
            if (tmp == val) {
                k++;
            } else {
                stack.push_back(tmp);
            }
        }
        int m = stack.size();
        for (int i=0; i<k; i++) {
            stack.push_back(0);
        }
        nums = stack;
        return m;
    }
};