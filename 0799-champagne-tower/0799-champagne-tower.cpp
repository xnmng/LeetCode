class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> row(query_row+1, 0);
        row[0] = poured;
        auto curRow{0};
        while (curRow != query_row) {
            // for (auto i : row) cout << i << " ";
            // cout << "\n";
            vector<double> next(query_row+1, 0);
            for (auto i = 0; i < row.size()-1; ++i) {
                if (row[i] <= 1) continue;
                double val{(row[i]-1)/2};
                next[i] += val;
                next[i+1] += val;
            }
            row = next;
            ++curRow;
        }
        // for (auto i : row) cout << i << " ";
        return row[query_glass] > 1 ? 1 : row[query_glass];
    }
};