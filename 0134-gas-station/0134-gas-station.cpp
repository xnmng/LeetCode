// https://leetcode.com/problems/gas-station/solutions/1706142/java-c-python-an-explanation-that-ever-exists-till-now/
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        auto sum{0};
        auto index{0};
        auto psum{0};
        for (auto i = 0; i < cost.size(); ++i) {
            sum += gas[i] - cost[i];
            psum += gas[i] - cost[i];
            if (psum < 0) {
                index = i+1;
                psum = 0;
            }
        }
        // for (auto i : net) cout << i << " ";
        return sum < 0 ? -1 : index;

    }
};

// [2]
// [2]

// [5,8,2,8]
// [6,5,6,6]

// [5,1,2,3,4]
// [4,4,1,5,1]

// [-1,3,-4,2]
// [-1,2,-2,0]

// [2,3,4]
// [3,4,3]
