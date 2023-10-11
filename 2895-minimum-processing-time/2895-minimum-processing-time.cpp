class Solution {
public:
    // each processor has 4 cores, each core should only perform 1 and only 1 task (from qn requirements)
    // would make sense then (to minimize finish time of all tasks), 
    // processor that becomes available earlier/later should take longer/shorter tasks
    int minProcessingTime(vector<int>& processorTime, vector<int>& tasks) {
        sort(processorTime.begin(), processorTime.end());
        sort(tasks.begin(), tasks.end(), greater<int>());
        int ans = INT_MIN;
        int temp;
        int temp2;
        for (auto i = 0; i < processorTime.size(); ++i) {
            temp = max(processorTime[i] + tasks[4 * i], processorTime[i] + tasks[4 * i + 1]);
            temp2 = max(processorTime[i] + tasks[4 * i + 2], processorTime[i] + tasks[4 * i + 3]);
            ans = max(ans, max(temp, temp2));
        }
        return ans;
    }
};