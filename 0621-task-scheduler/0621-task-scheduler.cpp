class Solution {
public:
    // TODO: understand this greedy solution
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> v(26, 0);
        int len = tasks.size(); // using len instead of usual n because of naming clash
        int maximum = 0;
        int freq = 0;
        for (auto i : tasks) {
            ++v[i - 'A'];
            if (v[i - 'A'] == maximum) ++freq;
            else if (v[i - 'A'] > maximum) {
                ++maximum;
                freq = 1;
            }
        }
        return max(len, (maximum - 1) * (n + 1) + freq);
    }
};