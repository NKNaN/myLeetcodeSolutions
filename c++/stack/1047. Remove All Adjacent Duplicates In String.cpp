class Solution {
public:
    string removeDuplicates(string s) {
        if (s.size() == 1) return s;
        stack<char> st;
        st.push(s[0]);
        bool popped = false;
        for (int i=1; i<s.size(); ++i) {
            if (!st.empty() && st.top() == s[i]) {
                st.pop();
                popped = true;
            } else {
                st.push(s[i]);
            }
        }
        if (!popped) return s;
        string ts = "";
        while (!st.empty()) {
            ts = st.top() + ts;
            st.pop();
        }
        return removeDuplicates(ts);
    }
};