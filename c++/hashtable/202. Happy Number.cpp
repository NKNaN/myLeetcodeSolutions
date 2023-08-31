class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> record;
        while (record.count(n) == 0) {
            if (n == 1) {
                return true;
            }
            record.insert(n);
            n = sqsum(n);
        }
        return false;
    }
    int sqsum(int x) {
        int sum = 0;
        while (x / 10 > 0) {
            int rem = x % 10;
            sum += rem*rem;
            x = x / 10;
        }
        return sum + x*x;
    }
};