// https://leetcode.com/problems/apply-operations-to-make-two-strings-equal/discuss/4144041/JavaC++Python-One-Pass-O(1)-Space
class Solution {
public:
    int minOperations(string s1, string s2, int x) {
        int ans = 0;
        // note: we will only have at most 2 as we will 'flip' as we traverse
        bool hasOne = false; // do we have any index in our prefix that is different
        
        int farCost = 0;
        int closeCost = 0;
        int bothCost = 0;
        
        for (auto i = 0; i < s1.size(); ++i) {
            if (s1[i] == s2[i]) {
                ++closeCost;
                ++bothCost;
                cout << "i=" << i << " ans=" << ans << " farCost=" << farCost 
                    << " closeCost=" << closeCost << " bothCost=" << bothCost << "\n";
                
                continue;
            }
            if (hasOne) {
                hasOne = false;
                ans = min(farCost + x, closeCost + 1);
                bothCost = min(farCost, closeCost);
            } else {
                hasOne = true;
                farCost = min(ans, bothCost + 1);
                closeCost = min(ans, bothCost + x);
            }
            cout << "i=" << i << " ans=" << ans << " farCost=" << farCost 
                << " closeCost=" << closeCost << " bothCost=" << bothCost << "\n";
            
        }
        
        return hasOne ? -1 : ans;
    }
};