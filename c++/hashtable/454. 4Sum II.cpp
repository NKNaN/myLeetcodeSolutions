class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> sum2;
        int tmp;
        for (int i=0; i<nums3.size(); i++) {
            for (int j=0; j<nums4.size(); j++) {
                tmp = - nums3[i] - nums4[j];
                if (sum2.count(tmp)){
                    sum2[tmp]++;
                } else {
                    sum2[tmp] = 1;
                }
            }  
        }

        int count = 0;
        for (int i=0; i<nums3.size(); i++) {
            for (int j=0; j<nums4.size(); j++) {
                tmp = nums1[i] + nums2[j];
                if (sum2.count(tmp)){
                    count += sum2[tmp];
                }
            }  
        }
        return count;
    }
};