class Solution {
public:
    // has to be in all 4 directions
    // group by each row and each col, sort
    // check that this element is not the first and last in its own row and col
    //
    // note: since constraints for x and y are small, 
    // we can also avoid sorting by storing for each row/col value, the smallest and largest in that row/col
    // the check will just be that its coordinate is not equal to the max + min for that row/col

    // no sorting solution
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        int ans = 0;

        vector<int> xdirmax(n+2, 0);
        vector<int> xdirmin(n+2, n+2);
        vector<int> ydirmax(n+2, 0);
        vector<int> ydirmin(n+2, n+2);
        // for each row/col[k], i want to know the min/max of that col/row!
        // (note the different axes!)
        for (auto& i : buildings) {
            xdirmax[i[1]] = max(i[0], xdirmax[i[1]]);
            xdirmin[i[1]] = min(i[0], xdirmin[i[1]]);
            ydirmax[i[0]] = max(i[1], ydirmax[i[0]]);
            ydirmin[i[0]] = min(i[1], ydirmin[i[0]]);
        }
        // - it should be a comparision, not an equality check!
        // else you will accept non-covered points since they dont match!
        // e.g. if im checking x == 1 and the bounds are (2,2)
        // - compare x coordinate with that row/col 
        // (which you get by indexing with col/row!)
        for (auto& i : buildings) {
            if (xdirmax[i[1]] > i[0] 
                && xdirmin[i[1]] < i[0] 
                && ydirmin[i[0]] < i[1] 
                && ydirmax[i[0]] > i[1]) ++ans; 

            // cout << i[0] << " " << i[1] << "\n";
            // cout << xdirmin[i[0]] << " " << xdirmax[i[0]] << " " 
            // << ydirmin[i[1]] << " " << ydirmax[i[1]] << "\n";
        }

        return ans;
    }


    // // check if its the same point
    // bool compare(vector<int>& v1, pair<int,int>& v2) {
    //     return v1[0] == v2.first && v1[1] == v2.second;
    // }

    // // with sorting solution
    // int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
    //     int ans = 0;

    //     unordered_map<int, vector<pair<int,int>>> xdir;
    //     unordered_map<int, vector<pair<int,int>>> ydir;
    //     for (auto& i : buildings) {
    //         xdir[i[0]].emplace_back(i[0], i[1]);
    //         ydir[i[1]].emplace_back(i[0], i[1]);
    //     }
    //     for (auto& [k,v] : xdir) sort(v.begin(), v.end());
    //     for (auto& [k,v] : ydir) sort(v.begin(), v.end());
    //     pair<int,int> front;
    //     pair<int,int> back;
    //     for (auto& i : buildings) {
    //         // cout << i[0] << " " << i[1] << "\n";
    //         front = xdir[i[0]].front();
    //         back = xdir[i[0]].back();
    //         // cout << front.first << " " << front.second << " " 
    //         // << back.first << " " << back.second << "\n";
    //         if (compare(i, front) || compare(i, back)) continue;
    //         front = ydir[i[1]].front();
    //         back = ydir[i[1]].back();
    //         // cout << front.first << " " << front.second << " " 
    //         // << back.first << " " << back.second << "\n";
    //         if (compare(i, front) || compare(i, back)) continue;
    //         ++ans;
    //     }

    //     return ans;
    // }
};