class TimeMap {
public:
    unordered_map<string, map<int, string, greater<int>>> mp;
    TimeMap() {
    }
    
    void set(string key, string value, int timestamp) {
        mp[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        if(mp.find(key) == mp.end()) return "";
        if(mp[key].find(timestamp) != mp[key].end())
            return mp[key][timestamp];
        
        //Since it is stored in decreasing order
        for(auto [prev_timestamp, val] : mp[key])
            if(prev_timestamp <= timestamp)
                return val;
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */