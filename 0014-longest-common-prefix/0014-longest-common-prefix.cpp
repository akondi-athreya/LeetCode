class TrieNode {
    public:
    int strings_below;
    int string_end_here;
    TrieNode *children[26];
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
    void add(string word) {
        TrieNode *curr = root;
        for(char c : word) {
            int index = c - 'a';
            if(curr->children[index] == NULL) {
                curr->children[index] = new TrieNode();
            }
            curr = curr->children[index];
            curr->strings_below++;
        }
        curr->string_end_here++;
    }
    int char_below(string prefix) {
        TrieNode *curr = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(curr->children[index] == NULL) {
                return 0;
            }
            curr = curr->children[index];
        }
        return curr->strings_below;
    }
};
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string dummy = strs[0];
        Trie trie;
        int n = strs.size();
        if(n == 1) return dummy;
        for(int i = 0 ; i < n ; i++) {
            trie.add(strs[i]);
        }
        int ans = 0;
        string ch = "";
        for(int i = 0 ; i < dummy.size() ; i++) {
            ch += dummy[i];
            if(trie.char_below(ch) != n) break;
            else {
                ans++;
            }
        }
        cout << ans;
        ch = "";
        if(ans <= 0) return "";
        for(int i = 0 ; i < ans ; i++) {
            ch += dummy[i];
        }
        return ch;
    }
};