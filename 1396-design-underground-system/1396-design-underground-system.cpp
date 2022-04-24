class UndergroundSystem {
    unordered_map<int,pair<string,int>> record;
    unordered_map<string,pair<int,int>>cnt;
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        record[id]={stationName,t};
    }
    
    void checkOut(int id, string stationName, int t) {
        t-=record[id].second;
        string st=record[id].first+","+stationName;
        cnt[st].first+=t;
        cnt[st].second++;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string st=startStation+","+endStation;
        return double(cnt[st].first)/cnt[st].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */