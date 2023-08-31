class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1, s2;
        for (int i=0; i<nums1.size(); i++) {
            s1.insert(nums1[i]);
        }
        for (int i=0; i<nums2.size(); i++) {
            s2.insert(nums2[i]);
        }
        vector<int> s1_s2;
        for (auto i=s1.begin(); i!=s1.end(); i++) {
            if (s2.count(*i) != 0) {
                s1_s2.push_back(*i);
            }
        }
        return s1_s2;
    }
};