class Solution {
public:
    int countSeniors(vector<string>& details) {
        int ans = 0;
        for (auto& i : details) {
            if (i[11] - '6' > 0) ++ans;
            else if (i[11] == '6' && i[12] - '0' > 0) ++ans; 
        }
        return ans;
    }
};