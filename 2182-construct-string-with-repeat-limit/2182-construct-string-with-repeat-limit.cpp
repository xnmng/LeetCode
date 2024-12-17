class Solution {
public:
    // use PQ to simulate
    // O(nlogk) time, O(k) space (i.e. k = 26)
    // greedily form largest string using min(freq, limit) * largest char + second largest char
    // until not possible anymore (i.e. no more second largest char), then return
    string repeatLimitedString(string s, int repeatLimit) {
        string ans = "";
        ans.reserve(s.size());
        vector<int> v(26, 0);
        for (char c : s) {
            ++v[c - 'a'];
        }
        priority_queue<int> pq; // store offset, not actual char
        for (int i = 0; i < 26; ++i) {
            if (v[i] > 0) pq.push(i);
        }
        int cur;
        int next;
        int count;
        while (!pq.empty()) {
            cur = pq.top();
            pq.pop();
            count = min(v[cur], repeatLimit);
            v[cur] -= count;
            ans.append(count, 'a' + cur);
            while (v[cur] > 0) {
                if (pq.empty()) break; // cannot alternate anymore
                next = pq.top();
                --v[next];
                if (v[next] == 0) pq.pop();
                ans += 'a' + next;
                count = min(v[cur], repeatLimit);
                v[cur] -= count;
                ans.append(count, 'a' + cur);
            }
        }
        return ans;
    }

    // // O(nk) time, O(k) space (i.e. k = 26)
    // // probably a more elegant way to write this...
    // string repeatLimitedString(string s, int repeatLimit) {
    //     string ans = "";
    //     ans.reserve(s.size());
    //     vector<int> v(26, 0);
    //     for (char c : s) {
    //         ++v[c - 'a'];
    //     }
    //     char prev = ' ';
    //     int count = 0;
    //     int distinct;
    //     bool added;
    //     while (ans.size() != s.size()) {
    //         distinct = 0;
    //         added = false;
    //         for (int i = 25; i >= 0; --i) {
    //             if (v[i] == 0) continue;
    //             else ++distinct;
    //             if (i + 'a' == prev) {
    //                 if (count == repeatLimit) continue;
    //                 ans += i + 'a';
    //                 --v[i];
    //                 ++count;
    //                 // cout << "add " << (char)(i + 'a') << " " << count << "\n";
    //                 added = true;
    //                 break;
    //             }
    //             else {
    //                 ans += i + 'a';
    //                 count = 1;
    //                 prev = i + 'a';
    //                 // cout << "add " << (char)(i + 'a') << " " << count << "\n";
    //                 --v[i];
    //                 added = true;
    //                 break;
    //             }
    //         }
    //         if (distinct == 1 && !added) break;
    //     }
    //     return ans;
    // }
};