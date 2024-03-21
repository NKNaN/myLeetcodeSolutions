class Solution {
public:
    int strStr(string haystack, string needle) {
        int len_needle = needle.length();
        if (len_needle > haystack.length()) {
            return -1;
        }

        int count_needle = 0;
        for (int i=0; i<haystack.length() - len_needle + 1; ++i) {
            if (haystack[i] == needle[0]) {
                for (int j=0; j<len_needle; ++j) {
                    if (haystack[i+j]==needle[j]) {
                        ++count_needle;
                    }
                }
                if (count_needle == len_needle) {
                    return i;
                } else {
                    count_needle = 0;
                }
            }
        }
        return -1;
    }
};