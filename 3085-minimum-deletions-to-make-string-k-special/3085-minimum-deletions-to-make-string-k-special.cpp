class Solution {
public:
    // think backwards:
    // let x be the character with the smallest frequency in the answer. 
    // out of the selected characters, 
    // optimal solution will never delete an occurrence of character x
    int minimumDeletions(string word, int k) {
        int ans = word.size();
        int temp;
        unordered_map<char, int> mp;
        for (char c : word) ++mp[c];
        for (auto [k1, v1] : mp) {
            // suppose v1 is the min char freq
            // calculate deletions needed
            temp = 0;
            for (auto [k2, v2] : mp) {
                if (k1 == k2) continue;
                if (v2 >= v1) temp += max(v2 - v1 - k, 0);
                else temp += v2;
            }
            // cout << k1 << " " << temp << "\n";
            ans = min(ans, temp);
        }
        return ans;
    }
};