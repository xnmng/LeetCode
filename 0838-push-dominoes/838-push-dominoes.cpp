// 2 pointers method (constant space, modifying input), consider different possible cases!
class Solution {
private:
    void helper(string& dominoes, char prev, int prevIndex, char cur, int curIndex) {
        if (cur == 'L' && prev == '.') {
            for (auto i = 0; i < curIndex; ++i) {
                dominoes[i] = 'L';
            }
        }
        else if (prev == 'R' && cur == 'L') {
            while (prevIndex < curIndex) {
                dominoes[prevIndex] = 'R';
                dominoes[curIndex] = 'L';
                ++prevIndex;
                --curIndex;
            }
        }
        else if (prev == cur) {
            for (auto i = prevIndex; i < curIndex; ++i) {
                dominoes[i] = prev;
            }
        }
    }
public:
    string pushDominoes(string dominoes) {
        auto prev{'.'};
        auto prevIndex{-1};
        auto cur{'.'};
        auto curIndex{-1};
        for (auto i = 0; i < dominoes.size(); ++i) {
            if (dominoes[i] != '.') {
                prev = cur;
                prevIndex = curIndex;
                cur = dominoes[i];
                curIndex = i;
                helper(dominoes, prev, prevIndex, cur, curIndex);
            }
        }
        if (cur == 'R') {
            for (auto i = curIndex; i < dominoes.size(); ++i) {
                dominoes[i] = 'R';
            }
        }
        return dominoes;
    }
};

// 2 pass method
// https://leetcode.com/problems/push-dominoes/discuss/1352339/C++-Simple-and-Clean-Easy-to-Understand-O(n)-Solution-With-detailed-Explanation
// class Solution {
// public:
//     string pushDominoes(string dominoes) {
//         vector<int> left(dominoes.size(), 0);
//         vector<int> right(dominoes.size(), 0);
//         for (auto i = 0; i < dominoes.size(); ++i) {
//             if (dominoes[i] == 'L') continue;
//             if (dominoes[i] == 'R') {
//                 right[i] = 1;
//             }
//             else if (i > 0 && right[i-1] > 0) right[i] = 1 + right[i-1];
//         }
//         for (auto i = static_cast<int>(dominoes.size()-1); i >= 0; --i) {
//             if (dominoes[i] == 'R') continue;
//             if (dominoes[i] == 'L') {
//                 left[i] = 1;
//             }
//             else if (i+1 < dominoes.size() && left[i+1] > 0) left[i] = 1 + left[i+1];
//         }
//         // for (auto i : left) cout << i << " ";
//         // cout << "\n";
//         // for (auto i : right) cout << i << " ";
//         // cout << "\n";
        
//         string ans;
//         for (auto i = 0; i < dominoes.size(); ++i) {
//             // 1 If both are 0 - we just copy what we had in dominoes.
//             // 2 If right[i] is 0 but left[i] is not, it means this domino falls to the left, and vice versa.
//             // 3 If they are both equal, which means that we have balance of the forces and we stay vertical.
//             // 4 If we have to different values in right[i] and left[i], we find the minimum which means that it's closer.
            
//             if (left[i] == right[i]) ans += '.'; // combine 1 and 3
//             else if (right[i] > 0 && left[i] == 0) ans += 'R';
//             else if (left[i] > 0 && right[i] == 0) ans += 'L';
//             else if (right[i] < left[i]) ans += 'R';
//             else ans += 'L';
//         }
//         return ans;
//     }
// };