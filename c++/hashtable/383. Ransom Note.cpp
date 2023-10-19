class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> ransomNote_map, magazine_map;
        for (int i=0; i<magazine.size(); i++) {
            if (magazine_map.count(magazine[i])) {
                ++magazine_map[magazine[i]];
            } else {
                magazine_map[magazine[i]] = 0;
            }
        }

        for (int i=0; i<ransomNote.size(); i++) {
            if (ransomNote_map.count(ransomNote[i])) {
                ++ransomNote_map[ransomNote[i]];
            } else {
                ransomNote_map[ransomNote[i]] = 0;
            }
        }

        for (auto kv: ransomNote_map) {
            if (!magazine_map.count(kv.first) || magazine_map[kv.first] < kv.second) {
                return false;
            }
        }
        return true;
    }
};