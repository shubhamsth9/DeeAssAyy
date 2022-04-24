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
        checkOutMap[checkIn.first + "_" + stationName].first += t - checkIn.second;
        checkOutMap[checkIn.first + "_" + stationName].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        auto& checkOut = checkOutMap[startStation + "_" + endStation];
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