class Solution {
public:
    int compareVersion(string version1, string version2) {
        int v1Index = 0;
        int v2Index = 0;
        int v1 = 0;
        int v2 = 0;
        while (v1Index < version1.size() 
               || v2Index < version2.size()) {
            while (v1Index < version1.size() 
                   && version1[v1Index] != '.') {
                v1 *= 10;
                v1 += version1[v1Index] - '0';
                ++v1Index;
            }
            while (v2Index < version2.size()
                   && version2[v2Index] != '.') {
                 v2 *= 10;
                 v2 += version2[v2Index] - '0';
                 ++v2Index;
            }
            if (v1 > v2) return 1;
            else if (v1 < v2) return -1;
            else {
                v1 = 0;
                v2 = 0;
                ++v1Index;
                ++v2Index;
            }
        }
        return 0;
    }
};
// "1.0.1"
// "1"