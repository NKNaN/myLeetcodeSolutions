class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> s1_s2;
        if (nums1.size() < nums2.size()) {
            unordered_map<int, int> s2;
            for (int i=0; i<nums2.size(); i++) {
                if (s2.count(nums2[i])) {
                    s2[nums2[i]]++;
                } else {
                    s2[nums2[i]] = 1;
                }
            }
            for (int i=0; i<nums1.size(); i++) {
                if (s2.count(nums1[i]) && s2[nums1[i]] > 0) {
                    s1_s2.push_back(nums1[i]);
                    s2[nums1[i]]--;
                }
            }
        } else {
            unordered_map<int, int> s1;
            for (int i=0; i<nums1.size(); i++) {
                if (s1.count(nums1[i])) {
                    s1[nums1[i]]++;
                } else {
                    s1[nums1[i]] = 1;
                }
            }
            for (int i=0; i<nums2.size(); i++) {
                if (s1.count(nums2[i]) && s1[nums2[i]] > 0) {
                    s1_s2.push_back(nums2[i]);
                    s1[nums2[i]]--;
                }
            }
        }
        return s1_s2;
    }
};