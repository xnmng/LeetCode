class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int rdiff = abs(coordinate1[0] - coordinate2[0]);
        int cdiff = abs(coordinate1[1] - coordinate2[1]);
        return (rdiff + cdiff) % 2 == 0;
    }
};