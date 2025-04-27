class Solution {
public:
    // check if its the same point
    bool compare(vector<int>& v1, pair<int,int>& v2) {
        return v1[0] == v2.first && v1[1] == v2.second;
    }

    // has to be in all 4 directions
    // group by each row and each col, sort
    // check that this element is not the first and last in its own row and col
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;

        unordered_map<int, vector<pair<int,int>>> xdir;
        unordered_map<int, vector<pair<int,int>>> ydir;
        for (auto& i : buildings) {
            xdir[i[0]].emplace_back(i[0], i[1]);
            ydir[i[1]].emplace_back(i[0], i[1]);
        }
        for (auto& [k,v] : xdir) sort(v.begin(), v.end());
        for (auto& [k,v] : ydir) sort(v.begin(), v.end());
        pair<int,int> front;
        pair<int,int> back;
        for (auto& i : buildings) {
            // cout << i[0] << " " << i[1] << "\n";
            front = xdir[i[0]].front();
            back = xdir[i[0]].back();
            // cout << front.first << " " << front.second << " " 
            // << back.first << " " << back.second << "\n";
            if (compare(i, front) || compare(i, back)) continue;
            front = ydir[i[1]].front();
            back = ydir[i[1]].back();
            // cout << front.first << " " << front.second << " " 
            // << back.first << " " << back.second << "\n";
            if (compare(i, front) || compare(i, back)) continue;
            ++ans;
        }

        return ans;
    }
};