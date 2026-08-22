class TimeMap {
private:
    unordered_map<string,unordered_map<int,string>>map;
public:
    TimeMap() {

    }
    
    void set(string key, string value, int timestamp) {
        map[key][timestamp]=value;
    }
    
    string get(string key, int timestamp) {
        if (map[key].count(timestamp)){
            return map[key][timestamp];
        }
        for (int x = timestamp-1; x>0; --x){
            if (map.count(key) and map[key].count(x)){
            return map[key][x];
        }
        }
        return "";
    }
};
