class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>> adjlist(n); // course X -> prerequisites of course X
        vector<vector<int>> adjlist2(n); // course X -> what courses needs course X
        for (auto& i : relations) {
            adjlist[i[1]-1].emplace_back(i[0]-1);
            adjlist2[i[0]-1].emplace_back(i[1]-1);
        }
        
        auto comp = [](pair<int,int> a, pair<int,int> b) 
                        { return a.first > b.first; };

        priority_queue<pair<int,int>,
                        vector<pair<int,int>>,
                            decltype(comp)> pq(comp); // <finish_time, course_id>
        for (auto i = 0; i < n; ++i) {
            if (adjlist[i].empty()) {
                // cout << "initial: adding id=" << i << " time=" << time[i] << "\n";
                pq.emplace(time[i], i);
            }
        }
        
        int ans = 0;
        unordered_set<int> s;
        while (!pq.empty()) {
            auto [t, id] = pq.top();
            pq.pop();
            ans = t;
            s.insert(id);
            // cout << "cur id=" << id << " " << t << "\n";
            for (auto i : adjlist2[id]) {
                // cout << "checking course " << i << "\n"; 
                bool canTake = true;
                for (auto j : adjlist[i]) {
                    if (s.find(j) == s.end()) {
                        canTake = false;
                        break;
                    }
                }
                if (canTake) {
                    pq.emplace(ans + time[i], i);
                    // cout << "adding id=" << i << " time=" << ans + time[i] << "\n";
                }
            }
        }
        // cout << "done\n";
        return ans;
    }
};