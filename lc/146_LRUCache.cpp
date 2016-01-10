struct cacheNode{
    int key, val;
    cacheNode *pre;
    cacheNode *next;
    cacheNode(int a, int b) : key(a), val(b), pre(nullptr), next(nullptr) {};
};

class LRUCache{
public:
    LRUCache(int capacity) {
        size = capacity;
        header = tail = nullptr;
    }
    
    int get(int key) {
        if (map.find(key) == map.end()){
            return -1;
        } else{
            cacheNode *p = map[key];
            if (p == header){
                return header->val;
            } else if (p == tail){
                cacheNode *pre = tail->pre;
                pre->next = nullptr;
                tail->pre = nullptr;
                header->pre = tail;
                tail->next = header;
                header = tail;
                tail = pre;
            } else{
                cacheNode *pre = p->pre;
                cacheNode *next = p->next;
                pre->next = next;
                next->pre = pre;
                p->next = header;
                p->pre = nullptr;
                header->pre = p;
                header = p;
            }
        }
        return header->val;
    }
    
    void set(int key, int value) {
        if (map.find(key) == map.end()){
            cacheNode *newNode = new cacheNode(key, value);
            map[key] = newNode;
            if (header == nullptr){
                header = tail = newNode;
            } else{
                newNode->next = header;
                header->pre = newNode;
                header = newNode;
            }
            if (map.size() > size){
                map.erase(tail->key);
                cacheNode *pre = tail->pre;
                pre->next = nullptr;
                delete tail;
                tail = pre;
            }
        } else{
            get(key);
            header->val = value;
        }
    }
private:
    int size;
    unordered_map<int, cacheNode*> map;
    cacheNode *header;
    cacheNode *tail;
};