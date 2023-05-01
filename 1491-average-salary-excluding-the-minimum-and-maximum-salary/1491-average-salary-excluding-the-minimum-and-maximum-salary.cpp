class Solution {
public:
    double average(vector<int>& salary) {
        double mini{DBL_MAX};
        double maxi{DBL_MIN};
        double sum{0};
        for (double i : salary) {
            sum += i;
            mini = min(mini, i);
            maxi = max(maxi, i);
        }
        return (sum - mini - maxi) / (salary.size()-2);
    }
};