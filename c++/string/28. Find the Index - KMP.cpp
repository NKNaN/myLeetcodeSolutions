class Solution {
public:
    int strStr(string haystack, string needle) {
        // construct prefix table
        int prefix_table[needle.size()];
        int pre_last = 0;
        prefix_table[0] = 0;
        int suf_last;
        for (suf_last = 1; suf_last < needle.size(); ++suf_last) {
            if (needle[suf_last] == needle[pre_last]) {
                prefix_table[suf_last] = pre_last + 1;
                ++pre_last;
            } else {
                while (pre_last > 0) {
                    pre_last = prefix_table[pre_last - 1];
                    if (needle[suf_last] == needle[pre_last]) {
                        prefix_table[suf_last] = pre_last + 1;
                        ++pre_last;
                        break;
                    }
                }
                if (pre_last == 0) prefix_table[suf_last] = 0;
            }
        }
        // for(int i=0;i<needle.size();++i){
        //     cout<<prefix_table[i]<<' ';
        // }
        
        // matching
        int start = 0;
        int i;
        for (i=0; i<haystack.size(); ++i) {
            while ((i<haystack.size()) && (start<needle.size()) && (haystack[i] == needle[start])) {
                ++start;
                ++i;
            }
            if (start == needle.size()) break;
            if (start >= 1) {
                start = prefix_table[start - 1];
                --i;
            }
        }
        if ((i == haystack.size()) && (start < needle.size())) {
            return -1;
        }
        return i - start;
    }

};