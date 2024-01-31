class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // course -> (unordered) set of prerequisites
        // given course k, we can find out what courses needed to be taken before we can take k
        unordered_map<int,unordered_set<int>> mp1; 
        // course -> set of courses it unlocks
        // given course k, we can find out what courses course k 'unlocks'
        unordered_map<int,unordered_set<int>> mp2;
        for (auto& p : prerequisites) {
            mp1[p[0]].insert(p[1]);
            mp2[p[1]].insert(p[0]);
        }
        vector<int> ans;
        ans.reserve(numCourses);
        queue<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (mp1.find(i) == mp1.end()) {
                q.push(i);
            }
        }
        int cur;
        // for each course c in the queue, we know that at the time it is processed, 
        // we are able to take the course, so we add c to our ans vector
        //
        // we go through all the courses c 'unlocks', unlocking it in our other hashmap,
        // and checking if we are now able to take the course. if we are, add it to the queue
        // 
        // we are also guaranteed that we only add each course once, 
        // because only at one point will the checked course be 'fully unlocked' 
        // and thus added to our queue
        while (!q.empty()) {
            cur = q.front();
            q.pop();
            ans.emplace_back(cur);
            for (auto i : mp2[cur]) {
                mp1[i].erase(cur);
                if (mp1[i].empty()) {
                    q.push(i);
                }
            }
        }
        return (ans.size() == numCourses) ? ans : vector<int>();
    }
};