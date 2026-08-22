class LRUCache {
private:
struct Node {
    int key;
    int value;
    Node* next = nullptr;
    Node* prev = nullptr;
    Node(int key, int value) : key(key), value(value){}
    Node() : key(0),value(0){}
};
void addNode(Node* n){
    Node * before = last->prev;
    before->next = n;
    n->prev = before;
    n->next = last;
    last->prev = n;
}
void remove(Node* n){
    Node* before = n->prev;
    Node* after = n->next;

    before->next = after;
    after->prev = before;
}

public:
    int cap;
    unordered_map<int,Node*>cache;
    Node* first = new Node;
    Node* last = new Node;
    LRUCache(int capacity) : cap(capacity){
        last->prev = first;
        first->next = last;
    }
    
    int get(int key) {
        if (cache.find(key) != cache.end()) {
            Node* node = cache[key];
            remove(node);
            addNode(node);
            return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (cache.find(key) != cache.end()){
            remove(cache[key]);
        }
        Node* n = new Node(key,value);
        addNode(n);
        cache[key]=n;
        
        if (cap < cache.size()){
            Node * lru = first->next;
            cache.erase(lru->key);
            remove(lru);
            delete lru;
        } 
        
    }
};
