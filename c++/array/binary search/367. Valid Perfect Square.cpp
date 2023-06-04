class Solution {
public:
    bool isPerfectSquare(int num) {
        int lo = -1;
        int hi = 50000;
        while (hi - lo > 1) {
            int mid = (lo + hi) / 2;
            long s = (long)mid * mid;
            if (num > s) {
                lo = mid;
            } else if (num < s) {
                hi = mid;
            } else {
                return true;
            }
        }
        return false;
    }
};