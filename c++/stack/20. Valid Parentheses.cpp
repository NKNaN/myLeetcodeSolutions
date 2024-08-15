class Solution {
public:
    bool isValid(string s) {
        if (s.size() == 1) return false;
        stack<char> st;
        for (int i=s.size()-1; i>=0; --i) {
            if (!st.empty()) {
                if (!matchChar(s[i], st.top())) {
                    st.push(s[i]);
                } else {
                    st.pop();
                }
            } else {
                st.push(s[i]);
            }
        }
        return st.empty();
    }
    bool matchChar(char pre, char last) {
        if (pre == '(' && last == ')') return true;
        if (pre == '{' && last == '}') return true;
        if (pre == '[' && last == ']') return true;
        return false;
    }
};