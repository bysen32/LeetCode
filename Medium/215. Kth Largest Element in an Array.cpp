/*优先队列解法*/
class mycomparison {
public:
    bool operator() (const int lhs, const int rhs) const {
        return (lhs > rhs);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, less<int>> pqueue;
        for (int num : nums) {
            pqueue.push(num);
            if (pqueue.size() > k) {
                pqueue.pop();
            }
        }
        return pqueue.top();
    }
};


