class monoQue {
    deque<int> dq; // front -> back: monotone decreasing
public:
    monoQue() {}

    void push(int v) {
        while (!dq.empty() && dq.back() < v) {
            dq.pop_back();
        }
        dq.push_back(v);
    }

    int pop() {
        int res = dq.front();
        dq.pop_front();
        return res;
    }

    int maxValue() {
        return dq.front();
    }
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        monoQue mq;
        mq.push(-10001);
        for (int i=0; i<k; ++i) {
            mq.push(nums[i]);
        }
        vector<int> result;
        result.push_back(mq.maxValue());
        for (int i=k; i<nums.size(); ++i) {
            if (nums[i-k] == mq.maxValue()) mq.pop();
            mq.push(nums[i]);
            result.push_back(mq.maxValue());
        }
        return result;
    }
};
