class Solution {
public:
    // if finalSum is odd, cannot generate maximum even split
    // since we want longest split
    // iteratively generate the even numbers starting with 2,4,6, ...
    // any remainder add to last element
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum % 2 == 1) return {};
        vector<long long> ans;
        int next = 2;
        while (finalSum >= next) {
            ans.emplace_back(next);
            finalSum -= next;
            next += 2;
        }
        ans.back() += finalSum;
        return ans;
    }
};