class Solution {
public:
    int similarPairs(vector<string>& words) {
        int ans = 0;
        // store encoding -> freq
        unordered_map<int,int> mp;
        for (auto& word : words) {
            int cur = 0;
            for (char c : word) {
                cur = cur | (1 << (c - 'a'));
            }
            ans += mp[cur];
            ++mp[cur];
        }
        return ans;
    }
};