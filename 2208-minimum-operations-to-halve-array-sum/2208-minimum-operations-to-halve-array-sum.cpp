class Solution {
public:
    int halveArray(vector<int>& nums) {
        auto ans{0};
        auto sum{0.0};
        priority_queue<double> pq;
        for (auto& i : nums) {
            pq.push(i);
            sum += i;
        }
        auto cur{sum};
        double num;
        while (cur * 2 > sum) {
            num = pq.top();
            pq.pop();
            num /= 2;
            ++ans;
            cur -= num;
            pq.push(num);
        }
        return ans;
    }
};

// at least half (no need to be more than half!)
// [1]