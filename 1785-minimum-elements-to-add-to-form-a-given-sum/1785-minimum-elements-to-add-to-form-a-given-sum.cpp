class Solution {
public:
    // greedily add the max until you cant
    int minElements(vector<int>& nums, int limit, int goal) {
        // final - initial
        long long sum = goal;
        for (int i : nums) sum -= i;
        return (abs(sum) % limit == 0 ? 0 : 1) + (abs(sum) / limit);
    }
};
// [2,2,2,5,1,-2]
// 5
// 126614243