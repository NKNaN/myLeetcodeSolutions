class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sublen = 0;
        int subhi = 0;
        int sublo = 0;
        int subsum = 0;
        int shortest = 1e5+1;
        while (sublo < nums.size()) {
            if (subsum < target) {
                if (subhi < nums.size()) {
                    subsum += nums[subhi];
                    subhi++;
                    sublen++;
                } else {
                    break;
                }
            } else{
                if (sublen < shortest) {
                    shortest = sublen;
                }
                subsum -= nums[sublo];
                sublo++;
                sublen--;
            }
            // cout<<sublo<<' '<<subhi<<' '<<endl;
            // cout<<sublen<<endl;
            // cout<<subsum<<endl;
        }
        if (shortest == 1e5+1) {
            return 0;
        } else {
            return shortest;
        }
    }
};