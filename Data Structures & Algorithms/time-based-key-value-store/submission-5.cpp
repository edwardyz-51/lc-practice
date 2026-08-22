class TimeMap {
public:
    unordered_map<string,map<int,string>>store;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto iterator = store[key].upper_bound(timestamp);
        return iterator==store[key].begin() ? "" : (*prev(iterator)).second;
    }
};
