class Solution {
public:
    void reverseString(vector<char>& s) {
        int len = s.size();
        int steps = len / 2;
        for (int i=0; i<steps; i++) {
            swap(s, i, len-1-i);
        }
    }
    void swap(vector<char>& s, int idx1, int idx2) {
        char tmp = s[idx1];
        s[idx1] = s[idx2];
        s[idx2] = tmp;
    }
};