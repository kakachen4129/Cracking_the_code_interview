struct TrieNode{
    bool isEnd;
    TrieNode* next[26];
    TrieNode(){
        isEnd = false;
        for (int i = 0; i < 26; i++)
            next[i] = nullptr;
    }
};
class WordDictionary {
    TrieNode *root;
public:
    WordDictionary(){
        root = new TrieNode();
    }
    // Adds a word into the data structure.
    void addWord(string word) {
        //if (root == nullptr)    root = new TrieNode();
        TrieNode *p = root;
        for (int i = 0; i < word.size(); i++){
            if (p->next[word[i]-'a'] == nullptr)
                p->next[word[i]-'a'] = new TrieNode();
            p = p->next[word[i]-'a'];
        }
        p->isEnd = true;
    }

    // Returns if the word is in the data structure. A word could
    // contain the dot character '.' to represent any one letter.
    bool search(string word) {
        return compare(word, 0, root, word.size());
    }
    
    bool compare(string word, int pos, TrieNode *p, int n){
        if (p == nullptr)   return false;
        if (pos >= n)   return p->isEnd;
        if (word[pos] == '.'){
            bool ret = false;
            for (int i = 0; i < 26; i++)
                ret = ret || compare(word, pos+1, p->next[i], n);
            return ret;
        } else{
            return compare(word, pos+1, p->next[word[pos]-'a'], n);
        }
    }
};

// Your WordDictionary object will be instantiated and called as such:
// WordDictionary wordDictionary;
// wordDictionary.addWord("word");
// wordDictionary.search("pattern");