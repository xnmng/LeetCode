class Solution {
public:
    // if any of the triplet elements are greater than target, 
    // dont consider this triplet (wont help us form the ans)
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        bool x = false;
        bool y = false;
        bool z = false;
        int n = triplets.size();
        for (int i = 0; i < n; ++i) {
            if (triplets[i][0] > target[0] ||
               triplets[i][1] > target[1] ||
               triplets[i][2] > target[2]) {
                continue;
            }
            if (triplets[i][0] == target[0]) x = true;
            if (triplets[i][1] == target[1]) y = true;
            if (triplets[i][2] == target[2]) z = true;
        }
        return x && y && z;
    }
};