class Solution {
public:
    string reverseStr(string s, int k) {
        string a = "";
        int lo = 0;
        int size = s.length();
        do {
            if (lo+2*k <= size) {
                for (int i=lo; i < lo+2*k; i++) {
                    if (k - 1 - i + lo >= 0) {
                        a += s[lo + k - 1 - i + lo];
                    } else {
                        a += s[i];
                    }
                }
            } else if (lo+k <= size) {
                for (int i=lo; i < size; i++) {
                    if (k - 1 - i + lo >= 0) {
                        a += s[lo + k - 1 - i + lo];
                    } else {
                        a += s[i];
                    }
                }
            } else {
                for (int i=size-1; i >= lo; i--) {
                    a += s[i];
                }
            }
            
            lo += 2 * k;
        } while (a.length() < size);
        return a;
    }
};