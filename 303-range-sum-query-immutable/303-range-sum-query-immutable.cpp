class NumArray {
    vector<int> v;
public:
    NumArray(vector<int>& nums) {
        auto sum{0};
        for (auto i : nums) {
            sum += i;
            v.push_back(sum);
        }
    }
    
    int sumRange(int left, int right) {
        if (left == 0) return v[right];
        return v[right] - v[left-1];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */