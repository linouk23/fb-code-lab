struct TrieNode {
    int count;
    string prefix;
    unordered_map<char, TrieNode*> children;
};

class Trie {
public:
    Trie(): root(new TrieNode) {}
    void addWord(const string& word) const {
        TrieNode* cur = root;
        for (int letterIndex = 0; letterIndex < word.length(); ++letterIndex) {
            char letter = word[letterIndex];
            bool hasLetter = cur->children.count(letter);
            if (!hasLetter) {
                cur->children[letter] = new TrieNode();
            }
            cur = cur->children[letter];
            cur->count += 1;
            cur->prefix = word.substr(0, letterIndex + 1);
        }
    }
    string getUniquePrefix(const string& word) const {
        TrieNode* cur = root;
        for (char letter : word) {
            cur = cur->children[letter];
            bool isUniquePrefix = (cur->count == 1);
            if (isUniquePrefix) { return cur->prefix; }   
        }
        return cur->prefix;
    }
private:
    TrieNode* root;
};

vector<string> Solution::prefix(vector<string> &words) {
    Trie* trie = new Trie();
    vector<string> prefixes;
    for (const string& word : words) {
        trie->addWord(word);
    }
    for (const string& word : words) {
        prefixes.emplace_back(trie->getUniquePrefix(word));
    }
    return prefixes;
}
