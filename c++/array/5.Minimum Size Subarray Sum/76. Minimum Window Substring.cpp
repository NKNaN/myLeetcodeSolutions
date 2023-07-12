class Solution {
public:
    string minWindow(string s, string t) {
        int sublo = 0;
        int subhi = 0;
        int minLen = s.length();
        int min_lo = 0;
        int min_hi = 0;
        unordered_map<char, int> t_map;
        deque<int> visited_indices; // visited char's (in t) index (in s) for current window
        unordered_map<char, int> visit_map;
        for (int i = 0; i < t.length(); i++) {
            if (t_map.count(t[i])) {
                t_map[t[i]] += 1;
            } else {
                t_map.insert({t[i], 1});
                visit_map.insert({t[i], 0});
            }
        }
        bool all_visited = 0;
        bool once_all_visited = 0;
        int count = 0; // if count == t_map.size() all_visited = 1
        // for(auto kv:t_map){
        //     cout<<kv.first<<' '<<kv.second<<endl;
        // }

        while (subhi <= s.length()) {
            if (!visited_indices.size()) {
                sublo = subhi;
            }
            // subhi right shift
            if (!all_visited) { // if not visit all char
                if (t_map.count(s[subhi])) {
                    visited_indices.push_back(subhi); // A(0) -> A(0) B(3)
                    visit_map[s[subhi]] += 1;
                    if (t_map[s[subhi]] == visit_map[s[subhi]]) { // count++
                        count++;
                    }
                    all_visited = check_all(t_map, count);  
                }
                subhi++;
            } else {
                // cout<<"len: "<<subhi - sublo<<endl;
                if (subhi - sublo <= minLen) {
                    minLen = subhi - sublo;
                    min_lo = sublo;
                    min_hi = subhi;
                }
                once_all_visited = 1;
                // sublo right shift
                int poped_idx = visited_indices.front();
                visited_indices.pop_front(); // A(0) B(3) C(5) -> B(3) C(5)
                visit_map[s[poped_idx]] -= 1;
                if (visit_map[s[poped_idx]] < t_map[s[poped_idx]]) {
                    count--;
                }
                sublo = visited_indices.front(); // 3
                all_visited = check_all(t_map, count);
            }
            // cout<<"count: "<<count<<endl;
            // cout<<"visit_all: "<<all_visited<<endl;
            // if (visited_indices.size()>0){
            //     for (auto i:visited_indices) {
            //         cout<<i<<' ';
            //     }
            //     cout<<endl;
            // }
            // for(auto kv:visit_map){
            //     cout<<kv.first<<' '<<kv.second<<endl;
            // }
            // cout<<"sublo: "<<s[sublo]<<" subhi: "<<s[subhi]<<endl;
            // cout<<"minLen: "<<minLen<<endl;
        }
        if (once_all_visited == 0) return "";
        else return s.substr(min_lo, minLen);
    }

    bool check_all(unordered_map<char, int>& mp, int c) {
        return c == mp.size();
    }
};