class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> time(3,0); // [m, p, g]
        vector<vector<int>> garbageCount(garbage.size(), vector<int>(3, 0));
        for (auto i = 0; i < garbage.size(); ++i) {
            for (auto j = 0; j < garbage[i].size(); ++j) {
                if (garbage[i][j] == 'M') ++garbageCount[i][0];
                if (garbage[i][j] == 'P') ++garbageCount[i][1];
                if (garbage[i][j] == 'G') ++garbageCount[i][2];
            }
        }
        auto count{0};
        // note that its j then i
        for (auto j = 0; j < 3; ++j) {
            for (auto i = 0; i < garbageCount.size(); ++i) {
                if (garbageCount[i][j] > 0) {
                    count += garbageCount[i][j];
                    time[j] = count;           
                }
                if (i < travel.size()) count += travel[i];
            }
            // cout << count << "\n";
            count = 0;
        }
        // cout << time[0] << " " << time[1] << " " << time[2] << "\n";
        return time[0] + time[1] + time[2];
    }
};