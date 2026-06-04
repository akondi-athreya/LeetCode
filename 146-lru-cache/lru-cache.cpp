class LRUCache {
public:
    class Node {
    public:
        int key;
        int val;
        Node* next;
        Node* prev;
        Node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    unordered_map<int, Node*> mp;
    int capacity;

    Node* head = new Node(-1, -1);
    Node* tail = new Node(-1, -1);

    LRUCache(int cap) {
        capacity = cap;
        head->next = tail;
        tail->prev = head;
    }

    void deleteNode (Node* node) {
        Node* prevNode = node->prev;
        Node* nextNode = node->next;
        prevNode->next = nextNode;
        nextNode->prev = prevNode;
    }

    void insertAfterHead (Node* node) {
        Node* currAfterHead = head->next;
        head->next = node;
        node->prev = head;
        node->next = currAfterHead;
        currAfterHead->prev = node;
    }
    
    int get(int key) {
        if (!mp.count(key)) return -1;
        Node* n = mp[key];

        deleteNode(n);
        insertAfterHead(n);

        return n->val;
    }
    
    void put(int key, int value) {
        if (mp.count(key)) {
            Node* n = mp[key];
            n->val = value;
            deleteNode(n);
            insertAfterHead(n);
        } else {
            if (mp.size() == capacity) {
                Node* n = tail->prev;
                mp.erase(n->key);
                deleteNode(n);
            }
            Node* n = new Node(key, value);
            mp[key] = n;
            insertAfterHead(n);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */