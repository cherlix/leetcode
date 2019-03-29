/*
 * @lc app=leetcode id=208 lang=cpp
 *
 * [208] Implement Trie (Prefix Tree)
 *
 * https://leetcode.com/problems/implement-trie-prefix-tree/description/
 *
 * algorithms
 * Medium (37.23%)
 * Total Accepted:    167.2K
 * Total Submissions: 448.7K
 * Testcase Example:  '["Trie","insert","search","search","startsWith","insert","search"]\n[[],["apple"],["apple"],["app"],["app"],["app"],["app"]]'
 *
 * Implement a trie with insert, search, and startsWith methods.
 * 
 * Example:
 * 
 * 
 * Trie trie = new Trie();
 * 
 * trie.insert("apple");
 * trie.search("apple");   // returns true
 * trie.search("app");     // returns false
 * trie.startsWith("app"); // returns true
 * trie.insert("app");   
 * trie.search("app");     // returns true
 * 
 * 
 * Note:
 * 
 * 
 * You may assume that all inputs are consist of lowercase letters a-z.
 * All inputs are guaranteed to be non-empty strings.
 * 
 * 
 */
class Trie {
public:
    struct Node {
        char value;
        bool can_terminate;
        map<char, Node> descendant;

        Node() : value(0), can_terminate(false) {}
        Node(char _value, bool _terminate) : value(_value), can_terminate(_terminate) {}
    };

    Node root;

    /** Initialize your data structure here. */
    Trie() {
        
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* cur = &root;
        for (int i = 0; i < word.size(); ++i) {
            char ch = word[i];
            bool terminate = (i == (word.size() - 1));
            
            if (cur->descendant.find(ch) == cur->descendant.end()) {
                cur->descendant[ch] = Node(ch, terminate);
            }

            cur = &cur->descendant[ch];
            
            if (terminate) {
                cur->can_terminate = true;
            }
        }
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* node = startsWithInternal(word);
        return node ? node->can_terminate : false; 
    }

    Node* startsWithInternal(const string& word) {
        Node* cur = &root;
        for (auto ch : word) {
            if (cur->descendant.find(ch) == cur->descendant.end()) {
                return nullptr;
            }

            cur = &cur->descendant[ch];
        }
        
        return cur;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* node = startsWithInternal(prefix);
        return (node != nullptr);        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

