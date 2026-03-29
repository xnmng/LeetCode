class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        vector<int> v1(26, 0);
        vector<int> v2(26, 0);
        ++v1[s1[0] - 'a'];
        ++v1[s1[2] - 'a'];
        ++v2[s2[0] - 'a'];
        ++v2[s2[2] - 'a'];
        if (v1 != v2) return false;
        vector<int> v3(26, 0);
        vector<int> v4(26, 0);
        ++v3[s1[1] - 'a'];
        ++v3[s1[3] - 'a'];
        ++v4[s2[1] - 'a'];
        ++v4[s2[3] - 'a'];
        if (v3 != v4) return false;
        return true;
    }
};