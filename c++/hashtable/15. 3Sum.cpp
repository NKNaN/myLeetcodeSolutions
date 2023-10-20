class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        nums = sort(nums);
        vector<vector<int>> result;
        int lo;
        int hi;
        int target;
        for (int i=0; i<nums.size(); i++) {
            target = -nums[i];
            if (target < 0) break;
            if (i>0 && nums[i] == nums[i-1]) continue;
            lo = i+1;
            hi = nums.size()-1;
            while (lo < hi) {
                if (nums[hi] + nums[hi-1] < target || nums[lo] + nums[lo+1] > target) {
                    break;
                } else {
                    if (nums[hi] + nums[lo] == target) {
                        result.push_back({nums[i], nums[lo], nums[hi]});
                        while (lo < hi && nums[lo] == nums[lo+1]) {
                            ++lo;
                        }
                        while (lo < hi && nums[hi] == nums[hi-1]) {
                            --hi;
                        }
                        ++lo;
                        --hi;
                    } else if (nums[hi] + nums[lo] < target) {
                        ++lo;
                    } else {
                        --hi;
                    }
                }
            }
        }
        return result;
    }

    vector<int> sort(vector<int>& arr) {
        int tmp;
        for (int i=0; i<arr.size(); i++) {
            for (int j=0; j<arr.size()-1-i; j++) {
                if (arr[j] > arr[j+1]) {
                    tmp = arr[j+1];
                    arr[j+1] = arr[j];
                    arr[j] = tmp;
                }
            }
        }
        return arr;
    }
};