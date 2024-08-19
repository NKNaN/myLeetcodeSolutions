class Solution {
private:
    class minHeap {
        vector<pair<int, int>> tree;
    public:
        minHeap() {}

        void percolateUp(int p) {
            if (p == 0) return;
            int parent = (p - 1) / 2;
            if (tree[parent].second > tree[p].second) {
                swap(tree[parent], tree[p]);
            }
            percolateUp (parent);
        }

        void percolateDown(int r) {
            if (2*r+2 < tree.size()) { //has left and has right
                int left_child = 2*r+1;
                int right_child = 2*r+2;
                if (tree[left_child].second < tree[right_child].second) {
                    if (tree[r].second > tree[left_child].second) swap(tree[left_child], tree[r]);
                    percolateDown(left_child);
                } else {
                    if (tree[r].second > tree[right_child].second) swap(tree[right_child], tree[r]);
                    percolateDown(right_child);
                }
            } else if (2*r+1 < tree.size()) { //only has left
                int left_child = 2*r+1;
                if (tree[r].second > tree[left_child].second) swap(tree[left_child], tree[r]);
            } else { // not child
                return;
            }
        }

        void insert(pair<int, int> v) {
            tree.push_back(v);
            percolateUp(tree.size() - 1);
        }

        pair<int, int> peek() {
            return tree[0];
        }

        void pop() {
            tree[0] = tree[tree.size() - 1];
            tree.resize(tree.size() - 1);
            percolateDown(0);
        }

        int size() {
            return tree.size();
        }

        // void printHeap() {
        //     cout<<"Heap: ";
        //     for (int i=0; i<tree.size(); ++i) {
        //         cout<<"("<<tree[i].first<<' '<<tree[i].second<<") ";
        //     }
        //     cout<<endl;
        // }
    };

public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for (int i=0; i<nums.size(); ++i) {
            if (mp.find(nums[i]) == mp.end()) {
                mp.insert({nums[i], 1});
            } else {
                ++mp[nums[i]];
            }
        }
        minHeap mh;
        for (auto kv:mp) {
            cout<<kv.first<<' '<<kv.second<<endl;
            if (mh.size() < k) {
                mh.insert(kv);
            } else {
                if (kv.second >= mh.peek().second) {
                    mh.insert(kv);
                    mh.pop();
                }
            }
            // mh.printHeap();
        }
        vector<int> result;
        for (int i=0; i<k; ++i) {
            pair<int, int> kv = mh.peek();
            result.push_back(kv.first);
            mh.pop();
        }
        return result;
    }
};