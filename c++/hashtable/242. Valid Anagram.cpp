class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> chars;
        for (int i=0; i<s.size(); i++) {
            if (chars.count(s[i])) {
                ++chars[s[i]];
            } else {
                chars.insert({s[i], 1});
            }
        }
        for (int i=0; i<t.size(); i++) {
            if (chars.count(t[i])) {
                --chars[t[i]];
            } else {
                return false;
            }
        }
        bool ret = true;
        for (auto it=chars.begin(); it!=chars.end(); it++) {
            if (it->second) {
                ret = false;
            }
        }
        return ret;
        // for (auto it = chars.begin(); it != chars.end(); it++) {
        //     cout<<it->first<<' '<<it->second<<endl;
        // }
    }
};