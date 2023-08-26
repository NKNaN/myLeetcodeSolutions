class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rts;
        for (int i=0; i<strs.size(); i++) {
            string label = string2label(strs[i]);
            if (rts.count(label)) {
                rts[label].insert(end(rts[label]), strs[i]);
            } else {
                vector<string> v;
                v.insert(end(v), strs[i]);
                rts[label] = v;
            }
        }
        vector<vector<string>> ret;
        for (auto it=rts.begin(); it!=rts.end(); it++) {
            ret.insert(end(ret), it->second);
        }
        // string s = string2label(strs[0]);
        // cout<<s<<endl;
        // vector<vector<string>> a = {{""}};
        return ret;
    }
    string string2label(string s) {
        int label[26] = {0};
        for (int i=0; i<s.size(); i++) {
            int num = s[i] - 'a';
            label[num]++;
        }
        string ret;
        for (int i=0; i<26; i++) {
            ret += label[i] + '0';
        }
        return ret;
    }
};