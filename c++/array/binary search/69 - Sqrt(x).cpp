class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }
        int n = 10000 * 5;
        vector<long> nums(n + 1); // [0,1,2,3,4,5,6,7,8] - [0,1,4,9,16,25,36,49,64]
        for (int i=0; i<nums.size(); i++) {
            nums[i] = (long)i * i;
        }
        int lo = -1;
        int hi = n + 1;
        int mid = -1;
        while (hi - lo > 1) {
            mid = (lo + hi) / 2;
            if (x > nums[mid]) {
                lo = mid;
            } else if (x < nums[mid]) {
                hi = mid;
            } else {
                return mid;
            }
        }
        return lo;
    }
};