class Solution {
public:
    int mySqrt(int x) {
        int lo = -1;
        int hi = 50000;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            long s = (long)mid * mid;
            if (x > s) {
                lo = mid;
            } else if (x < s) {
                hi = mid;
            } else {
                return mid;
            }
        }
        return lo;
    }
};