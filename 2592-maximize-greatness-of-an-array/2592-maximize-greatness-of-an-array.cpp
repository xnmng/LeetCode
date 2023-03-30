class Solution {
public:
    int maximizeGreatness(vector<int>& A) {
        unordered_map<int, int> count;
        int k = 0;
        for (int a : A)
            k = max(k, ++count[a]);
        // for (auto& [k,v] : count) {
        //     cout << k << " " << v << "\n";
        // }
        return A.size() - k;
    }
};