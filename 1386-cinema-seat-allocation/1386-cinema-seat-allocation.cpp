class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int,vector<int>> mp;
        for (auto& i : reservedSeats) {
            mp[i[0]].emplace_back(i[1]);
        }
        auto ans{2*n};
        bool left;
        bool centerLeft;
        bool right;
        bool centerRight;
        for (auto& [k,v] : mp) {
            left = true;
            centerLeft = true;
            right = true;
            centerRight = true;
            for (auto& i : v) {
                if (i == 2 || i == 3) left = false;
                else if (i == 4 || i == 5) centerLeft = false;
                else if (i == 6 || i == 7) centerRight = false;
                else if (i == 8 || i == 9) right = false;
            }
            // cout << k << "\n";
            // cout << left << " " << centerLeft << " " << centerRight << " " << right << "\n";
            // cout << ans << " ";
            if (left && centerLeft && (!centerRight || !right)) --ans; // put 1 left
            else if (right && centerRight && (!centerLeft || !left)) --ans; // put 1 right
            else if (centerLeft && centerRight && (!left || !right)) --ans; // put 1 middle
            else if ((!left || !centerLeft) && (!right || !centerRight)) ans -= 2; // cannot put any
            // cout << ans << "\n";
        }
        return ans;
    }
};

// 4
// [[4,3],[1,4],[4,6],[1,7]]