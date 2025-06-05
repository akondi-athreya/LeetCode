class TrieNode {
    public:
    int strings_below;
    int string_end_here;
    TrieNode* children[26];
    TrieNode() {
        this->strings_below = 0;
        this->string_end_here = 0;
        for(int i = 0 ; i < 26 ; i++) {
            children[i] = NULL;
        }
    }
};
class Trie {
public:
    TrieNode* root;
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* curr = root;
        for(char ch : word) {
            int index = ch - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->strings_below++;
        }
        curr->string_end_here++;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char c : word) {
            int index = c - 'a';
            if(curr->children[index] == NULL) {
                return false;
            }
            curr = curr->children[index];
        }
        if(curr->string_end_here > 0) return true;
        return false;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(curr->children[index] == NULL) {
                return false;
            }
            curr = curr->children[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */