class UndergroundSystem {
    unordered_map<int, int> custTime;
    unordered_map<int, string> custStart;
    unordered_map<string, int> count;
    unordered_map<string, int> totalDuration;
public:
    UndergroundSystem() {}
    
    void checkIn(int id, string stationName, int t) {
        custStart[id] = stationName;
        custTime[id] = t;
    }
    
    void checkOut(int id, string stationName, int t) {
        string path{custStart[id] + " " + stationName};
        int duration{t - custTime[id]};
        custStart.erase(id);
        custTime.erase(id);
        totalDuration[path] += duration;
        ++count[path];
    }
    
    double getAverageTime(string startStation, string endStation) {
        string path{startStation + " " + endStation};
        // cout << totalDuration[path] << "\n";
        return (1.0 * totalDuration[path]) / count[path];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */