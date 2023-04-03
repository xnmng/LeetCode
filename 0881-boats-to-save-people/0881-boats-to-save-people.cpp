class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        auto ans{0};
        auto left{0};
        auto right{static_cast<int>(people.size()-1)};
        while (left <= right) {
            if (people[left] + people[right] <= limit) {
                ++left;
                --right;                
            }
            else {
                --right;
            }
            ++ans;
        }
        return ans;
    }
};