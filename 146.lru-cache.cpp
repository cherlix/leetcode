/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 *
 * https://leetcode.com/problems/lru-cache/description/
 *
 * algorithms
 * Hard (24.40%)
 * Total Accepted:    272.5K
 * Total Submissions: 1.1M
 * Testcase Example:  '["LRUCache","put","put","get","put","get","put","get","get","get"]\n[[2],[1,1],[2,2],[1],[3,3],[2],[4,4],[1],[3],[4]]'
 *
 * 
 * Design and implement a data structure for Least Recently Used (LRU) cache.
 * It should support the following operations: get and put.
 * 
 * 
 * 
 * get(key) - Get the value (will always be positive) of the key if the key
 * exists in the cache, otherwise return -1.
 * put(key, value) - Set or insert the value if the key is not already present.
 * When the cache reached its capacity, it should invalidate the least recently
 * used item before inserting a new item.
 * 
 * 
 * Follow up:
 * Could you do both operations in O(1) time complexity?
 * 
 * Example:
 * 
 * LRUCache cache = new LRUCache( 2 /* capacity */ );
 * 
 * cache.put(1, 1);
 * cache.put(2, 2);
 * cache.get(1);       // returns 1
 * cache.put(3, 3);    // evicts key 2
 * cache.get(2);       // returns -1 (not found)
 * cache.put(4, 4);    // evicts key 1
 * cache.get(1);       // returns -1 (not found)
 * cache.get(3);       // returns 3
 * cache.get(4);       // returns 4
 * 
 * 
 */
class LRUCache {
public:
    LRUCache(int capacity) {
        m_capacity = capacity;
        m_head = nullptr;
        m_tail = nullptr;
    }
    
    int get(int key) {
        if (m_dict.find(key) == m_dict.end()) {
            return -1;
        } else {
            moveNodeToHead(m_dict[key]);
            return m_dict[key]->value;
        }
    }
    
    void put(int key, int value) {
        if (m_dict.find(key) != m_dict.end()) {
            moveNodeToHead(m_dict[key]);
            m_dict[key]->value = value;
            return;
        }
        
        if (m_dict.size() == m_capacity) {
            m_dict.erase(m_tail->key);
            removeLastElement();
        }
        
        Node* node = new Node(key, value);
        if (m_head == nullptr) {
            m_head = node;
        }
        if (m_tail == nullptr) {
            m_tail = node;
        }
        m_dict[key] = node;
        addNodeToHead(node);
    }
    
private:
    struct Node {
        int key;
        int value;
        Node* prev;
        Node* next;
        
        Node(int _key, int _val) : key(_key), value(_val), prev(nullptr), next(nullptr) {}
    };
    
    void moveNodeToHead(Node* node) {
        if (m_head == node) {
            return;
        }
        if (node->prev) {
            node->prev = node->next;
        }
        if (node->next) {
            node->next->prev = node->prev;
        }
        node->next = m_head->next;
        m_head->next->prev = node;
        m_head = node;
    }
    
    void addNodeToHead(Node* node) {
        if (m_head == node) {
            return;
        }
        node->next = m_head->next;
        m_head->next->prev = node;
        m_head = node;
    }
    
    void removeLastElement() {
        if (m_tail == nullptr) {
            return;
        }
        
        if (m_tail->prev) {
            Node* node = m_tail->prev;
            node->next = nullptr;
            delete m_tail;
            m_tail = node;
        }
    }
    
    unordered_map<int, Node*> m_dict;
    Node* m_head;
    Node* m_tail;
    int m_capacity;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

