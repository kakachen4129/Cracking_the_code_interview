class TrieNode {
public:
    // Initialize your data structure here.
    unordered_map<char, TrieNode*> next;
    bool isLast;
    char ch;
    TrieNode() {isLast = false;}
    TrieNode(char c) : ch(c), isLast(false) {};
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    void insert(string word) {
        TrieNode *p = root;
        for (const auto &ch : word){
            if (p->next.find(ch) == p->next.end()){
                TrieNode *newNode = new TrieNode(ch);
                p->next[ch] = newNode;
            }
            p = p->next[ch];
        }
        p->isLast = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode *p = root;
        for (const auto &ch : word){
            if (p->next.find(ch) == p->next.end())
                return false;
            p = p->next[ch];
        }
        return p->isLast;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode *p = root;
        for (const auto &ch : prefix){
            if (p->next.find(ch) == p->next.end())
                return false;
            p = p->next[ch];
        }
        return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");