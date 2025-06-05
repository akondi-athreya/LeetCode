class TrieNode {
    public:
    int strings_below;
    int string_end_here;
    TrieNode *children[26];
    vector<int> for_idx;
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
    TrieNode *root;
    Trie() {
        root = new TrieNode();
    }
    void add(string word, int index) {
        TrieNode* curr = root;
        for(char ch : word) {
            int idx = ch - 'a';
            if(curr->children[idx] == NULL) {
                curr->children[idx] = new TrieNode();
            }
            curr = curr->children[idx];
            curr->for_idx.emplace_back(index);
            curr->strings_below++;
        }
        curr->string_end_here++;
    }
    vector<int> idx_search(string prefix) {
        TrieNode *current = root;
        for(char c : prefix) {
            int index = c - 'a';
            if(current->children[index] == NULL) {
                return {};
            }
            current = current->children[index];
        }
        return current->for_idx;
    }
};
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie trie;
        sort(products.begin(), products.end());
        for(int i = 0; i < products.size(); i++) {
            trie.add(products[i], i);
        }
        vector<vector<string>> res;
        string prefix = "";
        for(int i = 0; i < searchWord.size(); i++) {
            prefix += searchWord[i];
            vector<int> idx = trie.idx_search(prefix);
            vector<string> temp;
            if(idx.size() > 3) {
                idx.resize(3);
            }
            for(int j = 0; j < idx.size(); j++) {
                temp.push_back(products[idx[j]]);
            }
            res.push_back(temp);
        }
        return res;
    }
};
















