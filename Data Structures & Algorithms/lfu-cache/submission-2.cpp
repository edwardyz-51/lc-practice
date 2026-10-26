class LFUCache {
    struct Node {
        int key;
        int val;
        int freq;
    };

    int capacity;
    int lfuCount;

    // freq -> nodes with that frequency
    // front = least recently used
    // back = most recently used
    unordered_map<int, list<Node>> freqMap;

    // key -> iterator to its node
    unordered_map<int, list<Node>::iterator> nodeMap;

    void counter(list<Node>::iterator node) {
        int key = node->key;
        int val = node->val;
        int freq = node->freq;

        freqMap[freq].erase(node);

        if (freq == lfuCount && freqMap[freq].empty()) {
            lfuCount++;
        }

        freqMap[freq + 1].push_back({key, val, freq + 1});

        nodeMap[key] = prev(freqMap[freq + 1].end());
    }

public:
    LFUCache(int capacity)
        : capacity(capacity), lfuCount(0) {}

    int get(int key) {
        if (!nodeMap.contains(key)) {
            return -1;
        }

        int val = nodeMap[key]->val;
        counter(nodeMap[key]);
        return val;
    }

    void put(int key, int value) {
        if (capacity == 0) {
            return;
        }

        if (nodeMap.contains(key)) {
            nodeMap[key]->val = value;
            counter(nodeMap[key]);
            return;
        }

        if (nodeMap.size() == capacity) {
            auto& list = freqMap[lfuCount];

            int keyToRemove = list.front().key;

            nodeMap.erase(keyToRemove);
            list.pop_front();
        }

        freqMap[1].push_back({key, value, 1});
        nodeMap[key] = prev(freqMap[1].end());

        lfuCount = 1;
    }
};