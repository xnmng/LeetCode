class Solution {
public:
    // since we need to remove half of the elements from both arrays, 
    // and our resultant goal is to maximize the number of unique remaining integers from both sets,
    // we will first remove any duplicates from both input arrays
    //
    // suppose there exists k common elements between both arrays after removal
    // if we need to remove more elements from either arrays (since we may not have had removed enough elements)
    // we should remove the common elements first
    // if we dont have any common elements left to remove, then we remove the remaining (unique) elements
    int maximumSetSize(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());
        
        int n1 = nums1.size();
        int n2 = nums2.size();
        
        int s1Removed = n1 - s1.size();
        int s2Removed = n2 - s2.size();
        
        int common = 0;
        for (int i : s1) {
            if (s2.find(i) != s2.end()) ++common;
        }
        
        int ans = s1.size() + s2.size() - common;
        
        if (s1Removed < n1/2) {
            common -= (n1/2) - s1Removed;
            if (common < 0) {
                ans += common;
                common = 0;
            }
        }
        
        if (s2Removed < n2/2) {
            common -= (n2/2) - s2Removed;
            if (common < 0) {
                ans += common;
            }
        }
        
        return ans;
    }
};