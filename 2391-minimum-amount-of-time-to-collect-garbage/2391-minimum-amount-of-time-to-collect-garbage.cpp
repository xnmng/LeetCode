// https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/discuss/2492774/JavaC++Python-Explanation-with-Observations
class Solution {
public:
//     Observation 1:
//     "While one truck is driving or picking up garbage, the other two trucks cannot do anything."
//     We can simply sum up the total running time for each truck,
//     they don't affect each other.

//     Observation 2:
//     "Picking up one unit of any type of garbage takes 1 minute."
//     We don't care how many units for each type,
//     we only care the total amount.

//     Observation 3:
//     "however, they do not need to visit every house."
//     We only care the position of the last garbage for each type
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        vector<int> last(3, 0); // [M, P ,G]
        vector<int> time(3, 0); // [M, P, G]
        for (auto i = 0; i < garbage.size(); ++i) {
            for (auto& j : garbage[i]) {
                if (j == 'M') {
                    ++time[0];
                    last[0] = i;
                }
                if (j == 'P') {
                    ++time[1];
                    last[1] = i;
                }
                if (j == 'G') {
                    ++time[2];
                    last[2] = i;
                }
            }
        }
        // cout << time[0] << " " << time[1] << " " << time[2] << "\n";
        for (auto i = 0; i < travel.size(); ++i) {
            if (last[0] > i) time[0] += travel[i];
            if (last[1] > i) time[1] += travel[i];
            if (last[2] > i) time[2] += travel[i];
        }
        // cout << last[0] << " " << last[1] << " " << last[2] << "\n";
        // cout << time[0] << " " << time[1] << " " << time[2] << "\n";
        return time[0] + time[1] + time[2];
    }
};

// unnecessary space usage
// class Solution {
// public:
//     int garbageCollection(vector<string>& garbage, vector<int>& travel) {
//         vector<int> time(3,0); // [m, p, g]
//         vector<vector<int>> garbageCount(garbage.size(), vector<int>(3, 0));
//         for (auto i = 0; i < garbage.size(); ++i) {
//             for (auto j = 0; j < garbage[i].size(); ++j) {
//                 if (garbage[i][j] == 'M') ++garbageCount[i][0];
//                 if (garbage[i][j] == 'P') ++garbageCount[i][1];
//                 if (garbage[i][j] == 'G') ++garbageCount[i][2];
//             }
//         }
//         auto count{0};
//         // note that its j then i
//         for (auto j = 0; j < 3; ++j) {
//             for (auto i = 0; i < garbageCount.size(); ++i) {
//                 if (garbageCount[i][j] > 0) {
//                     count += garbageCount[i][j];
//                     time[j] = count;           
//                 }
//                 if (i < travel.size()) count += travel[i];
//             }
//             // cout << count << "\n";
//             count = 0;
//         }
//         // cout << time[0] << " " << time[1] << " " << time[2] << "\n";
//         return time[0] + time[1] + time[2];
//     }
// };