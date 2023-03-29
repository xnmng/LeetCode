class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        auto count0{0};
        auto count1{0};
        for (auto i : students) {
            i == 0 ? ++count0 : ++count1;
        }
        for (auto i : sandwiches) {
            if (i == 0 && count0 == 0) break;
            else if (i == 1 && count1 == 0) break;
            i == 0 ? --count0 : --count1;
        }
        return count0 + count1;
    }
};