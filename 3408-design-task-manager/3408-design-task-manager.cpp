class TaskManager {
public:
    unordered_map<int,int> mp1; // taskid -> priority
    unordered_map<int,int> mp2; // taskid -> userid
    priority_queue<pair<int,int>> pq; // sort tasks by (priority, taskid)

    TaskManager(vector<vector<int>>& tasks) {
        for (auto& i : tasks) {
            add(i[0], i[1], i[2]);
        }
    }
    
    // add into data structures for bookkeeping
    void add(int userId, int taskId, int priority) {
        pq.push({priority, taskId});
        mp1[taskId] = priority;
        mp2[taskId] = userId;
    }
    
    // insert new entry into pq, umap keeps track of correct priority
    void edit(int taskId, int newPriority) {
        pq.push({newPriority, taskId});
        mp1[taskId] = newPriority;
    }
    
    // set task priority to -1 (sentinel value)
    void rmv(int taskId) {
        mp1[taskId] = -1;
    }
    
    // keep popping until we find a task with matching priority inside umap
    int execTop() {
        while(!pq.empty()) {
            auto [priority, taskId] = pq.top();
            pq.pop();
            if (priority == mp1[taskId]) {
                mp1[taskId] = -1;
                return mp2[taskId];
            }
        }
        return -1;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */