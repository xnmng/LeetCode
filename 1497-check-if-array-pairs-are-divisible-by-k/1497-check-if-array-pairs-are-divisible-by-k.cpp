class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<bool> v(k, false);
        int count = 0;
        for (int i : arr) {
            if ((i % k + k) % k == 0) v[(i % k + k) % k] = v[0] ^ true;
            else v[(i % k + k) % k] = v[k - (i % k + k) % k] ^ true;
            if (v[(i % k + k) % k]) ++count;
            else --count;
        }
        return count == 0;
    }
};
// [-1,1,-2,2,-3,3,-4,4]
// 3