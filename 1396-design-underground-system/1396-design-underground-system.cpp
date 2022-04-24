class UndergroundSystem {
public:
    unordered_map<int, pair<string, int>> checkInMap; //id - {startStation, time}
    unordered_map<string, pair<int, int>> checkOutMap; // route - {duration, count}
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        checkInMap[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        auto& checkIn = checkInMap[id];
        string route = checkIn.first + "_" + stationName;
        checkOutMap[route].first += t - checkIn.second;
        checkOutMap[route].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string route = startStation + "_" + endStation;
        auto& checkOut = checkOutMap[route];
        return (double) checkOut.first/checkOut.second ;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */