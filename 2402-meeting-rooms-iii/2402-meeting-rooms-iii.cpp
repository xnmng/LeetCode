class Solution {
public:
    // simulate the process
    // we need:
    //      1 pq for available rooms (sort by room number) <room_number>
    //      1 pq for occupied rooms (sort by end time); <end_time, room_number>
    int mostBooked(int n, vector<vector<int>>& meetings) {
        // sort meetings by start time (which is unique based on problem constraints)
        sort(meetings.begin(), meetings.end());
        
        // for (auto i : meetings) cout << i[0] << " " << i[1] << "\n";
        
        // comparator for occupied rooms:
        // return room with smallest end time
        // if there are multiple rooms with same smallest end time, 
        //      return smallest room number
        auto occupiedComp = [](pair<long,int> a, pair<long,int> b) { 
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        };
        
        // initialize the 2 pq's we need for simulation
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<long,int>, vector<pair<long,int>>, decltype(occupiedComp)> occupied(occupiedComp);
        for (int i = 0; i < n; ++i) available.push(i);
        
        // use long for all variables; 
        // worst case input (i.e. all variable values 10^5) max meeting time can exceed INT_MAX
        long startTime = 0;
        long duration;
        int room;
        long endTime;
        vector<int> count(n, 0);
        
        // simulate the process
        for (auto& meeting : meetings) {
            // if there was a previous startTime due to delay, keep as is
            startTime = max(startTime, (long) meeting[0]);
            // cout << "meeting start=" << startTime << "\n";
            duration = meeting[1] - meeting[0];
            // given t = startTime, from occupied pq, add back rooms that are available
            // note the equals: meeting range is [start, end); endTime == startTime is OK
            while (!occupied.empty() && occupied.top().first <= startTime) {
                available.push(occupied.top().second);
                occupied.pop();
            }
            
            // if no rooms available at t = startTime, 
            // find when next room available and update startTime value
            if (available.empty()) {
               startTime = occupied.top().first;
                available.push(occupied.top().second);
                occupied.pop();
            }
            
            // here, we know there exists at least 1 available room
            // add this meeting to available room
            // update room's count, add into occupied (with correct duration)
            room = available.top();
            available.pop();
            endTime = startTime + duration;
            ++count[room];
            occupied.emplace(endTime, room);
            // cout << "actual start=" << startTime << " in room " << room << " end time=" << endTime << "\n\n";
        }
        
        // for (auto i : count) cout << i << " ";
        // cout << "\n";
        
        // - get room number with most meetings held (tie broken with room number)
        // - since we are iterating in ascending order, 
        // we only need to check for room with greater meeting count
        // - as we are returning room number (aka index of our count vector),
        // we do not need to store freq, just index into vector O(1) operation
        int ans = 0;
        for (auto i = 1; i < n; ++i) {
            if (count[i] > count[ans]) ans = i;
        }
        return ans;
    }
};
// 4
// [[48,49],[22,30],[13,31],[31,46],[37,46],[32,36],[25,36],[49,50],[24,34],[6,41]]
/**
**/