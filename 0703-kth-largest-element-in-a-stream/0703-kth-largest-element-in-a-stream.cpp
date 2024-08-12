class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) : limit(k), pq(nums.begin(), nums.end()) {
        while (pq.size() > limit) pq.pop();
    }
    
    int add(int val) {
        pq.push(val);
        while (pq.size() > limit) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq;
    int limit;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */