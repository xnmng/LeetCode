class Solution {
public:
    // simulate both cases and return highest
    int maxHeightOfTriangle(int red, int blue) {
        int redFirst = 0;
        int blueFirst = 0;
        int redTemp = red;
        int blueTemp = blue;
        while (true) {
            if (redTemp < redFirst + 1) break;
            redTemp -= redFirst + 1;
            ++redFirst;
            if (blueTemp < redFirst + 1) break;
            blueTemp -= redFirst + 1;
            ++redFirst;
        }
        redTemp = red;
        blueTemp = blue;
        while (true) {
            if (blueTemp < blueFirst + 1) break;
            blueTemp -= blueFirst + 1;
            ++blueFirst;
            if (redTemp < blueFirst + 1) break;
            redTemp -= blueFirst + 1;
            ++blueFirst;
        }
        return max(redFirst, blueFirst);
    }
};